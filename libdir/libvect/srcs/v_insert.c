/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_insert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:51:59 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/23 00:10:54 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vect.h"

/*
**	> i is the position in the array in data units not bytes
**	> v_insert dublicates source material, into vector
*/

void	v_insert(t_vect *head, size_t i, void *data)
{
	size_t	index;

	if (head->len == head->cap)
		v_increase(head);
	index = i * head->data_size;
	ft_memmove(
		head->a + index + sizeof(data), 
		head->a + index, 
		head->len - index);
	ft_memcpy(head->a + index, &data, head->data_size);
	head->len = head->len + head->data_size;
	head->units = head->len / head->data_size;
}
