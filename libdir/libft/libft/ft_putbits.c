/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:09:07 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/17 19:29:40 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbits(int n, int bytes)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	bytes = 8 * bytes - 1;
	str = (char *)malloc(sizeof(char) * bytes + 1);
	while (bytes > 0)
	{
		i = i * 2;
		bytes--;
	}
	j = 0;
	while (i > 0)
	{
		str[j] = ft_itoa(n / i)[0];
		if (n / i != 0)
			n = n - i;
		i = i / 2;
		j++;
	}
	str[j] = '\0';
	ft_putstr(str);
}
