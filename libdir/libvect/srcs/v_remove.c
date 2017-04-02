/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_remove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:10:09 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/13 12:09:17 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vect.h"

/*
**	free memory that is pointed to by the item that
**	you are deleting
*/

void	v_remove(t_vect *vect, size_t i)
{
	size_t	index;
	size_t	d_size;
	void	*ptr;

	d_size = vect->data_size;
	index = i * vect->data_size;
	ptr = vect->a + index;
	ft_memmove(ptr, ptr + d_size, vect->len - index);
	vect->len = vect->len - vect->data_size;
	vect->units--;
	ft_bzero(vect->a + vect->len, vect->data_size);
}