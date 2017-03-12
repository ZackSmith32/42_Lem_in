/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_make_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:17:41 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/11 16:15:05 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		check_node(char *line)
{
	ft_printf("in: check_node\n");
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3)
	{
		printf("tablen = %d\n", ft_tablen(tab));
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
	printf("check node success\n");
	return (1);
}

/*
**	> v_insert copies what is in 'new' into the buffer already allocated
**		for the vector.
**	> Since it copies 'new', 'new' can be freed.  But, new contains a pointer
**		to new->name.  The memory that 'name' points to is still used by the 
**		vector, so we should not free it.  Also we free it later as we are 
**		deconstructing the vector, so no need to clean it up at this point. 
*/

static int		create_node(char *line, t_vect **nodes)
{
	ft_printf("in: create_node\n");
	char	**tab;
	t_lemd	*new;

	ft_printf("line = %s\n", line);
	tab = ft_strsplit(line, ' ');
	new = (t_lemd *)ft_memalloc(sizeof(t_lemd));
	new->name = ft_strdup(tab[0]);
	new->connections = NULL;
	v_insert(*nodes, (*nodes)->units, new);
	free(new);
	ft_freetab(tab);
	free(tab);
	printf("after insert\n");
	return (1);
}

int				make_nodes(char ***data, t_vect **nodes)
{
	ft_printf("in: make nodes\n");
	int		i;
	int		len;
	char	**this;

	this = *data;
	len = ft_tablen(this);
	i = 0;
	while (i < len)
	{
		if (check_node(this[i]))
		{
			create_node(this[i], nodes);
			// ft_deltab(data, i);
		}
		else
		{
			printf("check node failed\n");
		}
		i++;
	}
	printf("count = %d\n", i);
	return (1);
}
