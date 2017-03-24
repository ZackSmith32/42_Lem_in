/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_find_routes_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:11:53 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/23 17:02:13 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lemd	*find_start_node(t_vect *nodes)
{
	size_t	i;
	t_lemd	*temp;

	i = 0;
	while (i < nodes->units)
	{
		temp = *((t_lemd **)v_item(nodes, i));
		if (temp->s_e == 1)
		{
			return (temp);
		}
		i++;
	}
	return (NULL);
}
