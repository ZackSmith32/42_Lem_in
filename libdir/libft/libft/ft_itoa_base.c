/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:06:37 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 22:50:58 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long n, int base)
{
	int		i;
	char	lst[17];
	char	*str;

	ft_strcpy(lst, "0123456789abcdef");
	i = ft_numlen_base(n, base);
	str = (char *)ft_memalloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n != 0)
	{
		str[--i] = lst[n % base];
		n = n / base;
	}
	return (str);
}
