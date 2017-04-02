/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:07:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 19:00:50 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	*ptr = NULL; this will get triggered if **ptr has not been set to point
**		at a char*
*/

void	ft_puttab(char **ptr)
{
	int		i;

	i = 0;
	if (ptr == NULL)
		ft_putstr("top ptr NULL\n");
	if (*ptr == NULL)
		ft_putstr("*ptr = NULL\n");
	while (ptr[i] != 0)
	{
		ft_putstr("[");
		ft_putstr(ptr[i]);
		ft_putstr("]");
		ft_putstr(", ");
		i++;
	}
	ft_putstr("[0]");
	ft_putchar('\n');
}
