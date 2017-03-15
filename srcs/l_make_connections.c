/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_make_connections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 16:18:46 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		assign_connection(t_vect nodes, char *connection)
{
	int		i;
	char	**tab;
	t_lemd	*node;

	i = 0;
	tab = ft_strsplit(connection, '-');
	while (i < nodes->units)
	{
		node = *(t_lemd **)v_item(nodes, i)
		if (ft_strequ(node->name, tab[0]))
		{
			node->connection
		}
		i++;
	}
	return (0);
}

int		make_connections(t_vect *data, t_vect *nodes)
{
	char	*connection;

	while (data->units)
	{
		connection = *((char **)v_item(data, i));
		if (ft_strstr(connections, "-"))
		{
			printf("valid format\n");
			// if (!assign_connection(nodes, connection))
			// 	return (0);
			// free(data);
			// v_remove(data, i);
			i = 0;
		} 
		else
			return (0);
	}
	return (1);
}