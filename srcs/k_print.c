/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:23:15 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/11 16:59:37 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_lemd(t_vect **nodes)
{
	t_lemd	*vect;
	size_t	len;
	size_t	i;

	len = (*nodes)->units;
	i = 0
	while (i < len)
	{
		vect = (t_lemd *)v_item(i, *nodes);
		ft_printf("node: %s\n", vect->name);
	}
}