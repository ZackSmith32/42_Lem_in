/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_make_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:18:55 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/09 14:18:51 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	check_node(char *line, t_lemd *node)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3)
		return (0);
	node->name = tab[0];
	ft_freetab(tab);
	return (1);
}

static int	check_commands(char **data, t_lemd *node, int *i)
{
	char	*line;

	line = data[*i];
	if (ft_strncmp(line, "##", 2))
		return (0);
	ft_printf("data[%d] = %s\n", i, data[*i]);
	line += 2;
	if (ft_strcmp(line, "start") == 0)
		node->start = 1;
	else if (ft_strcmp(line, "end") == 0)
		node->end = 1;
	else
	{
		*i += 1;
		return (1);
	}
	if (check_node(data[*i + 1], node) == 0)
		return (0);
	*i += 2;
	return (1);
}




/*
int		make_graph(char ***data)
{
	int		i;
	t_lemd	*new;
	t_lemd	**lst;

	i = 0;
	ft_printf("in: make_graph\n");
	while ((*data)[i] != 0)
	{
		new = (t_lemd *)ft_memalloc(sizeof(t_lemd));
		if (ft_strlen((*data)[i]) == 0)
			return (0);
		// else if (check_commands((*data), new, &i) == 1)
		// 	;
		// else if (ft_strncmp((*data)[i], "#", 1))
		// 	i += 1;
		// else if (check_node((*data)[i], new))
		// 	i += 1;
		// else
		// 	ft_printf("bad line\n");
		// else if (check_connection())

		ft_printf("line = %s\n", (*data)[i]);
		ft_printf("name = %s\n", new->name);





		
		i++;
	}
	return (0);
}

*/

























