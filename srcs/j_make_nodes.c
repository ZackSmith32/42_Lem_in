/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_make_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:17:41 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/13 18:17:30 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_node(char *line)
{
	// ft_printf("in: check_node\n");
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3)
	{
		ft_freetab(tab);
		free(tab);
		return (0);
	}
	if (tab[0][0] == '#' || tab[0][0] == 'L')
	{
		ft_freetab(tab);
		free(tab);
		return (0);
	}
	ft_freetab(tab);
	free(tab);
	// printf("check node success\n");
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
	// ft_printf("in: create_node\n");
	char	**tab;
	t_lemd	*new;
	int		*temp;
	void	*ptr;

	ptr = NULL;
	// ft_printf("line = %s\n", line);
	tab = ft_strsplit(line, ' ');
	new = (t_lemd *)ft_memalloc(sizeof(t_lemd));
	printf("size of char* = %d\n", (int)sizeof(char *));
	printf("size of int = %d\n", (int)sizeof(int));
	printf("size of char ** = %d\n", (int)sizeof(char**));
	printf("sizeof lemd = %d\n", (int)sizeof(t_lemd));
	new->name = ft_strdup(tab[0]);
	new->connections = ptr;
	// temp = (int *)ft_memalloc(sizeof(int));
	// *temp = s_e;
	// new->s_e = temp;
	printf("s_e = %d\n", s_e);
	new->s_e = s_e;
	printf("name = %s, start/end = %d\n", new->name, new->s_e);
	v_insert(nodes, 0, new);

	free(new);
	ft_freetab(tab);
	free(tab);
	return (1);
}

int				make_nodes(t_vect *data, t_vect *nodes)
{
	// ft_printf("in: make nodes\n");
	int		i;
	char	*line;

	i = 0;
	while (i < data->units)
	{
		line = v_item(data, i);
		if (check_node(line))
		{
			create_node(line, nodes, 0);
			v_remove(data, i);
			i = 0;
		}
		else
		{
			i++;
		}
	}
	return (1);
}
