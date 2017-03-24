/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_lem_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:22:23 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/24 15:30:24 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// static int	output(t_vect nodes, t_vect dist_table)
// {
	// print_rooms_and_connections
// }

static int	lem_in()
{
	t_vect	*nodes;
	t_vect	*dist_table;

	nodes = v_new(0, sizeof(t_lemd *));
	dist_table = v_new(0, sizeof(t_lemd *));
	if (!parse(nodes))
		return (0);
	print_vect_lemd(nodes);
	if (!make_routes(nodes, &dist_table))
		return (0);
	print_vect_lemd(dist_table);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	print_vect_lemd(nodes);
	free_vector_nodes(nodes);
	free_vector_nodes(dist_table);
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc > 2)
		return (0);
	if (ft_strequ(argv[1], "-v"))
		g_verbose_flag = 1;
	if (!lem_in())
	{
		ft_puterror("Error: main");
		return (0);
	}
	ft_printf("%@cyan@s\n", "Hello World");
	return (0);
}










/*
 *	Data Parsing
 *	1. any line that does not meet any criteria stops the program
 *	2. comments #
 *	3. modifiers ##
 *
 *	Data Structures
 *	


 * Architecture
 * > parse data / create data structures
 *		> 
 * > algo
 * 		> calculate all paths
 *		> calculate wheather is makes sense to use 2 paths
 * > print stages

 */

