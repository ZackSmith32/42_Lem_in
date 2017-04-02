/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__wide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:44:12 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 16:58:04 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*s_wide_1(int wc)
{
	char		*ret;

	ret = (char *)ft_memalloc(2);
	ret[0] = (char)wc;
	ret[1] = '\0';
	return (ret);
}

static char		*s_wide_2(int wc)
{
	char		*ret;

	ret = (char *)ft_memalloc(3);
	ret[1] = (wc & 0x3f) | 0x80;
	ret[0] = (wc >> 6 & 0x1f) | 0xc0;
	ret[2] = '\0';
	return (ret);
}

static char		*s_wide_3(int wc)
{
	char		*ret;

	ret = (char *)ft_memalloc(4);
	ret[2] = (wc & 0x3f) | 0x80;
	ret[1] = (wc >> 6 & 0x3f) | 0x80;
	ret[0] = (wc >> 12 & 0x0f) | 0xe0;
	ret[3] = '\0';
	return (ret);
}

static char		*s_wide_4(int wc)
{
	char		*ret;

	ret = (char *)ft_memalloc(5);
	ret[3] = (wc & 0x3f) | 0x80;
	ret[2] = (wc >> 6 & 0x3f) | 0x80;
	ret[1] = (wc >> 12 & 0x3f) | 0x80;
	ret[0] = (wc >> 18 & 0x07) | 0xf0;
	ret[4] = '\0';
	return (ret);
}

char			*s_wide(wchar_t wide)
{
	char		*ret;

	if (wide <= 0x7f)
		ret = s_wide_1(wide);
	else if (wide <= 0x1fff)
		ret = s_wide_2(wide);
	else if (wide <= 0xffff)
		ret = s_wide_3(wide);
	else
		ret = s_wide_4(wide);
	ft_strcat(ret, "\0");
	return (ret);
}
