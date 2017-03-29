/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:23:15 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/29 10:17:08 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_rooms_and_connections(t_vect *nodes)
{
		t_lemd	*vect_item;
	size_t	len;
	size_t	i;

	len = nodes->units;
	i = 0;
	while (i < len)
	{
		vect_item = *((t_lemd **)v_item(nodes, i));
		if (vect_item->s_e == 1)
			ft_printf("##start\n");
		ft_printf("name: %s %d %d\n", vect_item->name, vect_item->coordinate_x, vect_item->coordinate_y);
		if (vect_item->s_e == 2)
			ft_printf(" : end");
		ft_printf("\n");
		print_connections(vect_item->connections);
		ft_printf("\n");
		i++;
	}
}

void		print_path_of_node(t_vect *curr_table_path, int tabs)
{
	t_lemd	*connect;
	size_t	i;
	int		j;

	i = 0;
	if (curr_table_path->units == 0)
		return ;
	j = -1;
	while (++j < tabs)
		ft_printf("	");
	while (i < curr_table_path->units)
	{
		connect = *((t_lemd **)v_item(curr_table_path, i));
		ft_printf("[%s]->", connect->name);
		i++;
	}
	ft_printf("\n");
}

void		print_connections(t_vect *connections)
{
	t_lemd	*connect;
	size_t	i;

	i = 0;
	if (connections->units == 0)
		return ;
	while (i < connections->units)
	{
		connect = *((t_lemd **)v_item(connections, i));
		ft_printf("  > %s\n", connect->name);
		i++;
	}
}

void	print_vect_lemd(t_vect *nodes)
{
	t_lemd	*vect_item;
	size_t	len;
	size_t	i;

	len = nodes->units;
	i = 0;
	while (i < len)
	{
		vect_item = *((t_lemd **)v_item(nodes, i));
		if (vect_item->s_e == 1)
			ft_printf("##start\n");
		ft_printf("name: %s %d %d\n", vect_item->name, vect_item->coordinate_x, vect_item->coordinate_y);
		if (vect_item->s_e == 2)
			ft_printf(" : end");
		ft_printf("\n");
		print_connections(vect_item->connections);
		ft_printf("\n");
		i++;
	}
}

void	print_vect_char(t_vect *data)
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
	ft_printf("\n");
}

void	print_str_vect(t_vect *str_vect)
{
	size_t		i;
	char		*str;

	i = 0;
	while (i < str_vect->units)
	{
		str = *((char **)v_item(str_vect, i));
		ft_printf("%s\n", str);
		i++;
	}
}
