/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_print_hq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:11:57 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/29 19:54:20 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_ants(t_vect *shortest_path)
{
	int			i;
	t_lemd		*node_in_path;

	i = (int)shortest_path->units - 1;
	while (i >= 0)
	{
		node_in_path = *((t_lemd **)v_item(shortest_path, i));
		if (node_in_path->ant != 0)
			ft_printf("L%d-%s ", node_in_path->ant, node_in_path->name);
		i--;
	}
	ft_printf("\n");
}

void		move_ants(t_vect *shortest_path, int ant_num, int *finished_ants)
{
	int		i;
	t_lemd	*before_node;
	t_lemd	*curr_node;

	i = (int)shortest_path->units - 1;
	while (i >= 1)
	{
		before_node = *((t_lemd **)v_item(shortest_path, i - 1)); 
		curr_node = *((t_lemd **)v_item(shortest_path, i));
		if (i == (int)shortest_path->units - 1 && curr_node->ant != 0)
			(*finished_ants)++;
		if (before_node->ant != 0)
			curr_node->ant = before_node->ant;
		else
			curr_node->ant = 0;
		i--;
	}
	before_node = *((t_lemd **)v_item(shortest_path, i)); 
	before_node->ant = ant_num;
}

void		free_shortest_path(t_vect *shortest_path_vect)
{
	t_lemd	*node;
	size_t	i;

	i = 0;
	while (i < shortest_path_vect->units)
	{
		node = *((t_lemd **)v_item(shortest_path_vect, i));
		free(node->name);
		free(node);
		i++;
	}
	free(shortest_path_vect->a);
	free(shortest_path_vect);
}

void		path_output(t_vect *nodes, t_vect *dist_table, int ant_count)
{
	int		*finished_ants;
	int		h;
	int		i;
	t_vect	*shortest_path_vect;

	shortest_path_vect = paths_vect(nodes, dist_table);
	h = 0;
	finished_ants = &h;
	i = 1;
	while (*finished_ants < ant_count)
	{
		if (i <= ant_count)
			move_ants(shortest_path_vect, i, finished_ants);
		else
			move_ants(shortest_path_vect, 0, finished_ants);			
		print_ants(shortest_path_vect);
		i++;
	}
	free_shortest_path(shortest_path_vect);
}
