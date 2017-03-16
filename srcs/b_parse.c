/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:48:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 17:42:17 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_vector(t_vect *nodes)
{
	t_lemd	*temp;
	int		i;

	i = 0;
	while (i < nodes->units)
	{
		temp = (t_lemd *)v_item(nodes, i);
		free(temp->name);
		// printf("connections addr = %p\n", temp->connections);
		// ft_freetab(temp->connections);
		// free(temp);
		i++;
	}
	free(nodes->a);
	free(nodes);
}

static int	make_graph(t_vect *data)
{
	ft_printf("in: make graph\n");
	int		i;
	t_vect	*nodes;

	nodes = v_new(0, sizeof(t_lemd *));
	if (!parse_comments(data, nodes))
		return (0);
	if (!make_nodes(data, nodes))
		return (0);
	if (!make_connections(data, nodes))
		return (0);
	print_char(data);
	print_lemd(nodes);
	free_vector(data);

	// free_vector(nodes);
	return (1);

}

static void	read_input(t_vect *data)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		v_insert(data, data->units, ft_strdup(line));
		free(line);
		i++;
	}
	free(line);
}

int			parse()
{
	t_vect	*data;
	int		len;

	data = v_new(0, sizeof(char *));
	read_input(data);
	if (data->len  == 0)
	{
		ft_puterror("no input");
		return (0);
	}
	if (!make_graph(data))
		return (0);
	return (1);
}



































