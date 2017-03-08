/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:22:23 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/07 21:44:09 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(int argc, char **argv)
{
	if (!parse(--argc, ++argv))
		return (0);
	lem_in()
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

