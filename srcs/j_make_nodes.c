/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_make_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:17:41 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/09 15:30:34 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		check_node(char *line)
{
	ft_printf("in: check_node\n");
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3)
		return (0);
	if (tab[0][0] == '#' || tab[0][0] == 'L')
		return (0);
	return (1);
}

static int		create_node(char *line, t_lemd ***nodes)
{
	ft_printf("in: create_node\n");
	char	**tab;
	t_lemd	*new;

	tab = ft_strsplit(line, ' ');
	new = (t_lemd *)ft_memalloc(sizeof(t_lemd));
	new->name = tab[0];
	ft_push(new, nodes);
	return (1);
}

int				make_nodes(char ***data, t_lemd ***nodes)
{
	ft_printf("in: make nodes\n");
	int		i;
	char	**this;

	i = 0;
	this = *data;
	while (data[i] != '\0')
	{
		if (check_node(this[i]))
		{
			// create_node(data[i], nodes);
			// ft_deltab(data, i);
		}
		else
			return (0);
	}
	return (1);
}
