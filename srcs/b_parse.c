/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:48:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/29 11:12:44 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		verbose_print(char *str)
{
	if (g_verbose_flag)
		ft_puterror(str);
}

static int	make_graph(t_vect *data, t_vect *nodes, int *ant_count, 
	t_vect *print_connects)
{
	if (!parse_ant_count(data, ant_count))
		return (0);
	if (!parse_comments(data, nodes))
	{
		verbose_print("Error: parse_comments\n");
		return (0);
	}
	if (!make_nodes(data, nodes))
	{
		verbose_print("Error: make_nodes\n");
		return (0);
	}
	if (!make_connections(data, nodes, print_connects))
	{
		verbose_print("Error: make_connections\n");
		return (0);
	}
	if (data->units != 0)
	{
		verbose_print("Error: invalid input\n");
		return (0);
	}
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

int			parse(t_vect *nodes, int *ant_count, t_vect *print_connects)
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
	if (!make_graph(data, nodes, ant_count, print_connects))
	{
		free(data->a);
		free(data);
		return (0);
	}
	free(data->a);
	free(data);
	return (1);
}



































