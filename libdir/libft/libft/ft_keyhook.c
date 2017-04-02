/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:54:20 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/28 19:33:27 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_keyhook(char key)
{
	int		bytes;
	char	*buff;

	buff = ft_memalloc(32);
	while ((bytes = read(0, buff, 32)))
	{
		if (ft_strchr(buff, key))
			break ;
	}
	return (bytes);
}
