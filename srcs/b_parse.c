/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:48:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/08 10:03:42 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	ok... weird error with gnl if the input does not end in a new line
**	pointer being freed not allocated
**	wtf gnl srsly
*/

static char	**read_input()
{
	char	*line;
	char	**data;

	data = ft_memalloc(sizeof(char *) * 1);
	while (get_next_line(0, &line) == 1)
	{
		ft_pushstr(&data, line);
		// ft_printf("%s\n", line);
		free(line);
	}
	free(line);
	ft_printf("where the fuck is this free error coming from?\n");
	return (data);
}


int			parse()
{
	char **data;

	data = read_input();
	ft_puttab(data);

	return (1);
}