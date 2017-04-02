/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_item.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:50:42 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/23 13:03:46 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vect.h"

void	*v_item(t_vect *vect, size_t index)
{
	// printf("index = %d, vect->units = %d\n", (int)index, (int)vect->units);
	if (index >= vect->units)
	{
		printf("v : index out of scope : return = NULL\n");
		return (NULL);
	}
	return (vect->a + (index * vect->data_size));
	// return ( &(vect->a[index]));
}
