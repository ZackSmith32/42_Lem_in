/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 20:37:24 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/27 15:12:15 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *str)
{
	long long	ans;
	int			neg;
	int			i;

	i = 0;
	neg = 1;
	ans = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (48 <= str[i] && str[i] < 58)
	{
		ans = str[i] - 48 + ans * 10;
		i++;
	}
	return (neg * ans);
}
