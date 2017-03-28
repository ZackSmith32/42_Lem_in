/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_find_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:20:55 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/27 12:20:22 by zsmith           ###   ########.fr       */
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
	int				node_se_val;

	dist_table = v_new(0, sizeof(t_lemd*));
	i = 0;
	while (i < nodes->units)
	{
		temp = (t_lemd *)ft_memalloc(sizeof(t_lemd));
		temp->name = ft_strdup(((*((t_lemd **)v_item(nodes, i))))->name);
		temp->connections = v_new(0, sizeof(t_lemd*));
		node_se_val = ((*((t_lemd **)v_item(nodes, i))))->s_e;
		if (node_se_val == 2)
			temp->s_e = 0;
		else
			temp->s_e = node_se_val;
		v_insert(dist_table, dist_table->units, temp);
		i++;
	}
	return (dist_table);
}

/*
**	> copy path from root to current
**	> add current to it's own path
**	> current_node is from 'node' vector
*/
void	add_node_to_table(t_lemd *root_node, t_lemd *list_node_child,
			t_vect *dist_table)
{
	printf("	in : add_node_to_table\n");
	size_t	i;
	t_lemd			*root_table_node;
	t_vect			*root_table_path;
	t_lemd			*curr_table_node;
	t_vect			*curr_table_path;

	printf("		list_node_child->name: %s\n", list_node_child->name);
	printf("		root_node->name: %s\n", root_node->name);
	root_table_node = search_nodes_by_name(dist_table, root_node->name);
	root_table_path = root_table_node->connections;
	curr_table_node = search_nodes_by_name(dist_table, list_node_child->name);
	curr_table_path = curr_table_node->connections;
	curr_table_node->s_e = root_table_node->s_e++;
	i = 0;
	printf("		root_table_path->units = %d\n", (int)root_table_path->units);
	print_path_of_node(root_table_path, 2);
	while (i < root_table_path->units)
	{
		v_insert(curr_table_path, i, *((t_lemd**)v_item(root_table_path, i)));
		i++;
	}
	printf("		i=%d\n", (int)i);
	// insert itself as the last step in the path.  This is so that
	// future nodes can copy it, and current node will be apart of the path
	// ansilary benefit of making the count of nodes equal distance.
	v_insert(curr_table_path, i, list_node_child);
	print_path_of_node(curr_table_path, 2);
	printf("	out: add_node_to_table\n");
}

/*
**	> root_node is from the nodes vector, not the table vector.
**	> all variable with 'node', and without 'table' are from the node vector.
*/
void	populate_dist_table(t_lemd *root_node, t_vect *dist_table, t_vect *queue)
{
	printf("in : populate_dist_table root_node->name: %s\n", root_node->name);
	size_t			i;
	t_lemd			*list_node_child;
	t_lemd			*table_node_child;
	
	// exit condition for recursion if end, or no more connection in queue
	i = 0;
	printf("		(root_node->connections)->units = %d\n", (int)(root_node->connections)->units);
	while (i < (root_node->connections)->units)
	{
		list_node_child = *((t_lemd **)v_item(root_node->connections, i));
		table_node_child = search_nodes_by_name(dist_table, list_node_child->name);
		printf("		table_node_child->name = %s, s_e = %d\n", table_node_child->name, table_node_child->s_e);
		if (table_node_child->s_e == 0)
		{
			add_node_to_table(root_node, list_node_child, dist_table);
			v_insert(queue, queue->units, list_node_child);
		}
		if (ft_strequ(list_node_child->name, "0"))
			return ;
		i++;
	}
	if (ft_strequ(root_node->name, "5"))
		return ;
	v_remove(queue, 0);	
	printf("		queue:\n");
	print_connections(queue);
	printf("		queue done\n");
	populate_dist_table(*(t_lemd **)v_item(queue, 0), dist_table, queue);
}

int		make_routes(t_vect *nodes, t_vect **dist_table)
{
	printf("in : find_routes\n");
	t_vect		*queue;
	t_lemd		*start_node;
	t_lemd		*start_node_table;

	*dist_table = create_dist_table(nodes);
	// print_vect_lemd(dist_table);

	queue = v_new(0, sizeof(t_lemd *));
	start_node = find_start_node(nodes);
	v_insert(queue, 0, start_node);
	
	// start node is in dist_table, but it points to the same node that nodes points to
	// so, when we update the s_e of the dist_table nodes, we are doing if for nodes
	// as well.  Wiull probably have to save 
	start_node_table = find_start_node(*dist_table);
	start_node_table->s_e = 0;
	v_insert(start_node_table->connections, 0, start_node_table);
	
	populate_dist_table(*(t_lemd **)v_item(queue, 0), *dist_table, queue);
	// print_vect_lemd(dist_table);
	

	printf("after: populate_dist_table\n");
	return (1);
}



// need to figure out if nodes is getting copied over to dist table..
// of if dist table is it's own thing










