/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:23:15 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 17:36:40 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_lemd(t_vect *nodes)
{
	t_lemd	*vect_item;
	size_t	len;
	size_t	i;

	len = nodes->units;
	i = 0;
	while (i < len)
	{
		vect_item = *((t_lemd **)v_item(nodes, i));
		ft_printf("name: %s", vect_item->name);
		if (vect_item->s_e == 1)
			ft_printf(" : start");
		if (vect_item->s_e == 2)
			ft_printf(" : end");
		if (vect_item->connections)
			print_char(vect_item->connections);
		ft_printf("\n\n");
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
		line = *((char **)v_item(data, i));
		ft_printf("\n > %s", line);
		i++;
	}
}

t_lemd	*return_match(t_vect *nodes, char *name)
{
	int		i;
	t_lemd	*node;

	i = 0;
	while (i < nodes->units)
	{
		node = *((t_lemd **)v_item(nodes, i));
		if (node->name == name)
			return (node);
		i++;
	}
	return (0);
}
