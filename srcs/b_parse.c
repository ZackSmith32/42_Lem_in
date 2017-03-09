/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:48:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/09 14:18:42 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		make_graph(char ***data)
{
	int		i;
	t_lemd	*new;
	t_lend	**nodes;

	make_nodes(data, &nodes);




}

static char	**read_input()
{
	char	*line;
	char	**data;

	data = ft_memalloc(sizeof(char *) * 1);
	while (get_next_line(0, &line) == 1)
	{
		ft_pushstr(&data, line);
		free(line);
	}
	free(line);
	return (data);
}


int			parse()
{
	char **data;

	data = read_input();
	ft_puttab(data);
	if (data[0] == 0)
	{
		ft_puterror("no input");
		return (0);
	}
	make_graph(&data);
		// create nodes
		// create connections

	return (1);
}