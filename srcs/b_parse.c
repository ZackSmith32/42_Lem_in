/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:48:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/10 10:37:30 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_vector(t_vect *nodes)
{
	t_lemd	*temp;
	int		len;
	int		i;

	len = nodes->units;
	i = 0;
	while (i < len)
	{
		temp = (t_lemd *)v_item(i, nodes);
		free(temp->name);
		// printf("connections addr = %p\n", temp->connections);
		// ft_freetab(temp->connections);
		// free(temp);
		i++;
	}
	free(nodes->a);
	free(nodes);
}

static int	make_graph(char ***data)
{
	ft_printf("in: make graph\n");
	int		i;
	t_lemd	*new;
	t_vect	*nodes;

	nodes = v_new(0, sizeof(t_lemd *));
	if (!make_nodes(data, &nodes))
		return (0);


	free_vector(nodes);
	return (1);

}

static void	read_input(char ***data)
{
	printf("in: read_input\n");
	char	*line;
	int		i;

	*data = ft_memalloc(sizeof(char *) * 1);
	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		ft_pushstr(data, line);
		free(line);
		i++;
	}
	free(line);
}

int			parse()
{
	printf("in: parse \n");
	char	**data;
	int		len;


	read_input(&data);
	printf("len = %d\n", ft_tablen(data));
	ft_puttab(data);
	len = ft_tablen(data);
	// if (len == 0)
	// {
	// 	ft_puterror("no input");
	// 	return (0);
	// }
	make_graph(&data);
		// create nodes
		// create connections
	ft_freetab(data);
	free(data);
	return (1);
}
