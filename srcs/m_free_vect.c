/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_free_vect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:21:13 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/22 20:06:26 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_vector_nodes(t_vect *nodes)
{
	t_lemd	*temp;
	size_t	i;

	i = 0;
	while (i < nodes->units)
	{
		temp = *((t_lemd **)v_item(nodes, i));
		free(temp->name);
		free((temp->connections)->a);
		free(temp->connections);
		i++;
	}
	free(nodes->a);
	free(nodes);
}
