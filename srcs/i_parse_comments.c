/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_parse_comments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:59:22 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 14:38:02 by zsmith           ###   ########.fr       */
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

static int	make_s_e(t_vect *data, t_vect *nodes, size_t i, int s_e)
{
	char	*se_line;
	char	*se_command;
	t_lemd	*node;
	int		num;

	se_command = *((char **)v_item(data, i));
	se_line = *((char **)v_item(data, i + 1));
	if (check_node(se_line))
	{
		create_node(se_line, nodes, s_e);
		node = (t_lemd *)v_item(nodes, 0);
		free(se_command);
		free(se_line);
		v_remove(data, i);
		v_remove(data, i);
		return (1);
	}
	else
		return (0);


}

int			parse_comments(t_vect *data, t_vect *nodes)
{
	size_t	i;
	char	*line;

	i = 0;
	while (i < data->units)
	{
		line = *((char **)v_item(data, i));
		if (check_s_e(line))
		{
			if (!make_s_e(data, nodes, i, check_s_e(line)))
				return (0);
			i = 0;
		}
		else if (!ft_strncmp("#", line, 1))
		{
			free(line);
			v_remove(data, i);
			i = 0;
		}
		else
			i++;
	}
	return (1);
}



























