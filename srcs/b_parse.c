/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:48:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/22 16:03:10 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	make_graph(t_vect *data)
{
	ft_printf("in: make graph\n");
	t_vect	*nodes;

	nodes = v_new(0, sizeof(t_lemd *));
	if (!parse_comments(data, nodes))
	{
		if (g_verbose_flag)
			printf("Error: parse_comments\n");
		return (0);
	}
	if (!make_nodes(data, nodes))
	{
		if (g_verbose_flag)
			printf("Error: make_nodes\n");
		return (0);
	}
	if (!make_connections(data, nodes))
	{
		if (g_verbose_flag)
			printf("Error: make_connections\n");
		return (0);
	}
	print_lemd(nodes);
	free_vector_nodes(nodes);
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

	data = v_new(0, sizeof(char *));
	read_input(data);
	if (data->len  == 0)
	{
		if (g_verbose_flag)
			ft_puterror("Error: No input\n");
		return (0);
	}
	if (!make_graph(data))
		return (0);
	return (1);
}



































