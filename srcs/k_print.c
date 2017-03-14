/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:23:15 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/13 17:27:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_lemd(t_vect *nodes)
{
	t_lemd	*vect;
	size_t	len;
	size_t	i;

	len = nodes->units;
	i = 0;
	while (i < len)
	{
		vect = (t_lemd *)v_item(nodes, i);
		ft_printf("name: %s\n", vect->name);
		i++;
	}
}

void	print_char(t_vect *data)
{
	char	*line;
	size_t	i;
	size_t	len;

	len = data->units;
	i = 0;
	while (i < len)
	{
		line = (char *)v_item(data, i);
		ft_printf("datas: %s\n", line);
		i++;
	}
}
