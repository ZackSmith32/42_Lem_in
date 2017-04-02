/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_pop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:04:14 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/23 18:23:09 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vect.h"

/*
**	must remember to free popped pointer
**	still need to work out how this works with the void pointer
*/
void	*v_pop(t_vect *vect)
{
	void	*temp;

	temp = (void *)ft_memalloc(sizeof(void *));
	ft_memcpy(temp, v_item(vect, 0), vect->data_size);
	v_remove(vect, 0);
	return (temp);
}
