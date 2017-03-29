/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_make_connections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:38 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/29 10:18:28 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lemd	*search_nodes_by_name(t_vect *nodes, char *search_name)
{
	size_t	i;
	t_lemd	*temp;

	i = 0;
	while (i < nodes->units)
	{
		temp = *((t_lemd **)v_item(nodes, i));
		if (ft_strequ(temp->name, search_name))
			return (temp);
		i++;
	}
	// printf("search nodes return null\n");
	return (NULL);
}

/*
**	> second if statement is to guard against repeat connections
*/
int		assign_connection(t_vect *nodes, char *connection, t_vect *print_connects)
{
	size_t	i;
	char	**tab;
	t_lemd	*temp;
	t_lemd	*node_to_connect;

	i = 0;
	tab = ft_strsplit(connection, '-');
	temp = search_nodes_by_name(nodes, tab[0]);
	node_to_connect = search_nodes_by_name(nodes, tab[1]);
	if (!temp || !node_to_connect)
	{
		if (g_verbose_flag)
			ft_puterror("Error: assign_connection\n");
		return (0);
	}
	if (!search_nodes_by_name(temp->connections, tab[1]))
	{
		v_insert(temp->connections, 0, node_to_connect);
		v_insert(print_connects, print_connects->units, ft_strdup(connection));
	}
	ft_freetab(tab);
	free(tab);
	return (1);
}

int		assign_connection_reverse(t_vect *nodes, char *connection)
{
	size_t	i;
	char	**tab;
	t_lemd	*temp;
	t_lemd	*node_to_connect;

	i = 0;
	tab = ft_strsplit(connection, '-');
	temp = search_nodes_by_name(nodes, tab[1]);
	node_to_connect = search_nodes_by_name(nodes, tab[0]);
	if (!temp || !node_to_connect)
	{
		if (g_verbose_flag)
			ft_puterror("Error: assign_connection\n");
		return (0);
	}
	if (!search_nodes_by_name(temp->connections, tab[0]))
		v_insert(temp->connections, 0, node_to_connect);
	ft_freetab(tab);
	free(tab);
	return (1);
}

void	innitiate_connections(t_vect *nodes)
{
	size_t	i;
	t_lemd	*node;

	i = 0;
	while (i < nodes->units)
	{
		node = *((t_lemd **)v_item(nodes, i));
		node->connections = v_new(0, sizeof(t_lemd *));
		i++;
	}
}

int		make_connections(t_vect *data, t_vect *nodes, t_vect *print_connects)
{
	char	*connection;

	innitiate_connections(nodes);
	while (data->units)
	{
		connection = *((char **)v_item(data, 0));
		// might want to turn this into a function with more checks
		// check if the connection is in the list
		if (ft_strstr(connection, "-")) 
		{
			if (!assign_connection(nodes, connection, print_connects) || 
				!assign_connection_reverse(nodes, connection))
				return (0);
			free(connection);
			v_remove(data, 0);
		} 
		else
		{
			if (g_verbose_flag)
				ft_puterror("Error: connection formatting\n");
			return (0);
		}
	}
	return (1);
}





























