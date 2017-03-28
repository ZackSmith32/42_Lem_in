/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:48:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/27 10:54:57 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	make_graph(t_vect *data, t_vect *nodes, int *ant_count)
{
	ft_printf("in: make graph\n");

	if (!parse_ant_count(data, ant_count))
	{
		if (g_verbose_flag)
			printf("Error: parse_ant_count\n");
		return (0);
	}
	if (!parse_comments(data, nodes))
	{
		if (g_verbose_flag)
			printf("Error: parse_comments\n");
		return (0);
	}
	// print_lemd(nodes);
	// print_vect_char(data);
	if (!make_nodes(data, nodes))
	{
		if (g_verbose_flag)
			printf("Error: make_nodes\n");
		return (0);
	}
	// print_lemd(nodes);
	// print_vect_char(data);
	if (!make_connections(data, nodes))
	{
		if (g_verbose_flag)
			printf("Error: make_connections\n");
		return (0);
	}
	free(data->a);
	free(data);
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

int			parse(t_vect *nodes, int *ant_count)
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
	if (!make_graph(data, nodes, ant_count))
		return (0);
	return (1);
}



































