/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_make_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:17:41 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/09 14:33:34 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		check_node(char *data)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3)
		return (0);
	if (tab[0][0] == '#' || tab[0][0] == 'L')
		return (0);
}

int				make_nodes(char ***data, t_lemd ***nodes)
{
	while (data[i] != '\0')
		if (check_node(data[i]))
		{
			create_node(data[i], nodes);
			ft_deltab(data, i);
		}
		else
			return (0);
}
