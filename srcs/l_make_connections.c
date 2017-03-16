/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_make_connections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 17:39:52 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		assign_connection(t_vect *nodes, char *connection)
{
	int		i;
	char	**tab;
	t_lemd	*node;

	i = 0;
	tab = ft_strsplit(connection, '-');
	while (i < nodes->units)
	{
		node = *((t_lemd **)v_item(nodes, i));
		if (ft_strequ(node->name, tab[0]))
		{
			v_insert(node->connections, 0, ft_strdup(tab[1]));
			ft_freetab(tab);
			free(tab);
			return (1);
		}
		i++;
	}
	ft_freetab(tab);
	free(tab);
	return (0);
}

void	innitiate_connections(t_vect *nodes)
{
	int		i;
	t_lemd	*node;

	i = 0;
	while (i < nodes->units)
	{
		node = *((t_lemd **)v_item(nodes, i));
		node->connections = v_new(0, sizeof(char *));
		i++;
	}
}


int		make_connections(t_vect *data, t_vect *nodes)
{
	char	*connection;

	innitiate_connections(nodes);
	while (data->units)
	{
		connection = *((char **)v_item(data, 0));
		if (ft_strstr(connection, "-"))
		{
			if (!assign_connection(nodes, connection))
				return (0);
			free(connection);
			v_remove(data, 0);
		} 
		else
			return (0);
	}
	return (1);
}





























