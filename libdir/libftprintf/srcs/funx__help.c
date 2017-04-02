/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:15:12 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 22:27:25 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned long long	ft_abs(long long num)
{
	unsigned long long z;

	if (num < 0)
		z = num * -1;
	else
		z = num;
	return (z);
}

char						*ft_itoa3(long long nbr)
{
	char				*ans;
	int					i;
	unsigned long long	n;
	int					neg;

	neg = 0;
	if (nbr < 0)
		neg = 1;
	n = ft_abs(nbr);
	i = ft_numlen_base(n, 10) + (neg == 1 ? 1 : 0);
	ans = (char *)malloc(sizeof(char) * (i + 1));
	ans[i] = '\0';
	if (n == 0)
		ans[--i] = 48;
	while (n != 0)
	{
		ans[--i] = n % 10 + 48;
		n = n / 10;
	}
	if (neg == 1)
		ans[0] = '-';
	return (ans);
}
