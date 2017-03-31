/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_make_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:17:41 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/29 19:55:45 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_node(char *line)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3 || tab[0][0] == '#' || tab[0][0] == 'L')
	{
		ft_freetab(tab);
		free(tab);
		return (0);
	}
	ft_freetab(tab);
	free(tab);
	return (1);
}

/*
**	> v_insert copies the pointer 'new' into the buffer already allocated
**		for the vector.
**	> Since it copies 'new', 'new' can be freed.  But, new contains a pointer
**		to new->name.  The memory that 'name' points to is still used by the 
**		vector, so we should not free it.  Also we free it later as we are 
**		deconstructing the vector, so no need to clean it up at this point. 
**	> s_e: 0 = nothing, 1 = start, 2 = end
*/

int		create_node(char *line, t_vect *nodes, int s_e)
{
	char	**tab;
	t_lemd	*new_node;
	void	*ptr;

	ptr = NULL;
	tab = ft_strsplit(line, ' ');

	new_node = (t_lemd *)ft_memalloc(sizeof(t_lemd));
	new_node->name = ft_strdup(tab[0]);
	new_node->coordinate_x = ft_atoi(tab[1]);
	new_node->coordinate_y = ft_atoi(tab[2]);
	new_node->s_e = s_e;
	v_insert(nodes, 0, new_node);
	ft_freetab(tab);
	free(tab);
	return (1);
}

int				make_nodes(t_vect *data, t_vect *nodes)
{
	size_t	i;
	char	*line;

	i = 0;
	while (i < data->units)
	{
		line = *((char **)v_item(data, i));
		if (check_node(line))
		{
			create_node(line, nodes, 0);
			free(line);
			v_remove(data, i);
			i = 0;
		}
		else
			i++;
	}
	return (1);
}
