/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:48:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/09 15:19:09 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		make_graph(char ***data)
{
	ft_printf("in: make graph\n");
	int		i;
	t_lemd	*new;
	t_lemd	**nodes;

	nodes = ft_memalloc(sizeof(t_lemd*) * 1);
	if (!make_nodes(data, &nodes))
		return (0);


	return (1);

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