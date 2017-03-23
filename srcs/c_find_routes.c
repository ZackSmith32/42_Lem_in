/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_find_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:20:55 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/23 13:02:43 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	duplicates nodes table essentially
*/
t_vect	*create_dist_table(t_vect *nodes)
{
	printf("in : create_dist_table\n");
	size_t			i;
	t_vect			*dist_table;
	t_lemd			*temp;

	dist_table = v_new(0, sizeof(t_lemd*));
	i = 0;
	while (i < nodes->units)
	{
		temp = (t_lemd *)ft_memalloc(sizeof(t_lemd));
		temp->name = ((*((t_lemd **)v_item(nodes, i))))->name;
		temp->connections = v_new(0, sizeof(t_lemd*));
		temp->s_e = ((*((t_lemd **)v_item(nodes, i))))->s_e;
		v_insert(dist_table, dist_table->units, temp);
		i++;
	}
	return (dist_table);
}

/*
**	> current_node is from 'node' vector
*/
void	add_node_to_table(t_lemd *root_node, t_lemd *current_node,
			t_vect *dist_table)
{
	printf("in : add_node_to_table\n");
	size_t	i;
	t_lemd			*root_table_node;
	t_vect			*root_table_path;
	t_lemd			*curr_table_node;
	t_vect			*curr_table_path;

	root_table_node = search_nodes_by_name(dist_table, root_node->name);
	root_table_path = root_table_node->connections;
	curr_table_node = search_nodes_by_name(dist_table, current_node->name);
	curr_table_path = curr_table_node->connections;
	curr_table_node->s_e = root_table_node->s_e++;
	i = 0;
	printf("	root_table_path->units = %d\n", (int)root_table_path->units);
	while (i < root_table_path->units)
	{
		v_insert(curr_table_path, i, *((t_lemd**)v_item(root_table_path, i)));
		i++;
	}
	v_insert(curr_table_path, i, current_node);
}

/*
**	> root_node is from the nodes vector, not the table vector.
**	> all variable with 'node', and without 'table' are from the node vector.
*/
void	populate_dist_table(t_lemd *root_node, t_vect *dist_table, t_vect *queue)
{
	printf("in : populate_dist_table\n");
	size_t			i;
	t_lemd			*current_node;
	t_lemd			*root_table_node;
	
	printf("	queue->units = %d\n", (int)queue->units);
	printf("	root_node->s_e = %d\n", root_node->s_e);
	// exit condition for recursion if end, or no more connection in queue
	if (root_node->s_e == 2)
		return ;
	i = 0;
	printf("	root_node->connections->units = %d\n", (int)(root_node->connections)->units);
	while (i < (root_node->connections)->units)
	{
		current_node = *((t_lemd **)v_item(root_node->connections, i));
		printf("	current_node->name = %s\n", current_node->name);
		root_table_node = search_nodes_by_name(dist_table, root_node->name);
		add_node_to_table(root_node, current_node, dist_table);
		v_insert(queue, queue->units, current_node);
		i++;
	}
	printf("	queue:\n");
	print_connections(queue);
	printf("	queue done\n");
	// populate_dist_table(*(t_lemd **)v_item(queue, 0), dist_table, queue);
}

int		make_routes(t_vect *nodes)
{
	printf("in : find_routes\n");
	t_vect		*dist_table;
	t_vect		*queue;
	t_lemd		*start_node;
	t_lemd		*start_node_table;

	dist_table = create_dist_table(nodes);
	print_vect_lemd(dist_table);
	queue = v_new(0, sizeof(t_lemd));
	start_node = find_start_node(nodes);
	v_insert(queue, 0, start_node);
	start_node_table = find_start_node(dist_table);
	start_node_table->s_e = 0;
	v_insert(start_node_table->connections, 0, start_node_table);
	populate_dist_table(start_node, dist_table, queue);
	print_vect_lemd(dist_table);
	printf("after: populate_dist_table\n");
	return (1);
}



// need to figure out if nodes is getting copied over to dist table..
// of if dist table is it's own thing










