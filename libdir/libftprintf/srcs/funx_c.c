/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:24:42 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 19:49:00 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	c_func(t_conv_obj *obj, va_list args)
{
	int		d;
	char	*e;

	free(obj->str);
	star_args(obj, args);
	d = -1;
	if (!ft_strcmp(obj->len_f, "l"))
	{
		obj->str = s_wide(va_arg(args, wint_t));
		if (obj->str[0] == 0)
			obj->extra += 1;
	}
	else
	{
		d = va_arg(args, int);
		if (d == 0)
			obj->extra += 1;
		e = (char *)ft_memalloc(2);
		e[0] = (char)d;
		e[1] = '\0';
		obj->str = e;
	}
	d_width(obj);
	if (d == 0)
		obj->str[obj->width - 1] = d;
}

void	big_c_func(t_conv_obj *obj, va_list args)
{
	ft_strcpy(obj->len_f, "l");
	c_func(obj, args);
	return ;
}
