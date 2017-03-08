/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_constructors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:27:08 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/07 22:41:45 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lemd			*data_constructor(char *name, char **connections)
{
	t_lemd		*new;

	new = (t_lemd *)ft_memalloc(sizeof(t_lemd));
	new->name = name;
	new->connections = connections;
	return (new);
}

t_path			*path_constructor(char *name, int len, t_path *n_node, 
				t_path *n_path)
{
	t_path		*new;

	new = (t_path *)ft_memalloc(sizeof(t_path));
	new->name = name;
	new->len = len;
	new->n_node = n_node;
	new->n_path = n_path;
	return (new);
}