/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_parse_comments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:59:22 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/13 18:14:53 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			check_s_e(char *line)
{
	int		holder;

	if (ft_strequ(line, "##start") == 1)
		holder = 1;
	else if (ft_strequ(line, "##end") == 1)
		holder = 2;
	else
		holder = 0;
	return (holder);
}

static int	make_s_e(t_vect *data, t_vect *nodes, size_t i, int holder)
{
	char	*line;
	t_lemd	*node;
	int		num;

	line = v_item(data, i + 1);
	if (check_node(line))
	{
		create_node(line, nodes, holder);
		printf("i = %d, len = %d, cap = %d, units = %d\n", (int)i, (int)nodes->len, (int)nodes->cap, (int)nodes->units);
		node = (t_lemd *)v_item(nodes, 0);
		num = node->s_e;
		ft_printf("%p\n", num);
		if (num)
			printf("~~~~~~ holder = %s, s_e = %d\n", node->name, num);
		v_remove(data, i);
		v_remove(data, i);
		return (1);
	}
	else
		return (0);


}

int			parse_comments(t_vect *data, t_vect *nodes)
{
	printf("in : parse_comments data->units = %d\n", (int)data->units);
	size_t	i;
	int		counter;
	int		holder;
	char	*line;

	counter = 0;
	i = 0;
	while (i < data->units)
	{
		line = v_item(data, i);
		holder = check_s_e(line);
		if (holder)
		{
			printf("****************** new s/e ****************\n");
			if (!make_s_e(data, nodes, i, holder))
				return (0);

			i = 0;
			printf("****************** out s/e ****************\n");

		}
		else if (!ft_strcmp("##", line))
		{
			v_remove(data, i);
			i = 0;
		}
		else
			i++;
	}
	printf("len = %d, cap = %d, units = %d\n", (int)nodes->len, (int)nodes->cap, (int)nodes->units);
	print_lemd(nodes);
	print_char(data);
	return (1);
}



























