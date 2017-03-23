/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_find_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:20:55 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/22 21:37:17 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_vect	*create_dist_table(t_vect *nodes)
{
	t_vect			*dist_table;
	t_dist_table	temp;

	dist_table = v_new(nodes->units, sizeof(t_dist_table));
	i = 0;
	while (i < nodes->units)
	{
		temp = (t_dist_table *)ft_memalloc(sizeof(t_dist_table));
		temp->name = *((t_lemd **)v_item(nodes, i))->name;
		v_insert(dist_table, temp);
		i++;
	}
	return (dist_table);
}

void	populate_dist_table(t_vect *nodes, t_vect *dist_table)
{

	while (i < dist_table_)
}




int		find_routes(t_vect *nodes)
{
	t_vect		*dist_table;

	dist_table = create_dist_table(nodes);
}