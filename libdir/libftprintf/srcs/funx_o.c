/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:52:00 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 23:51:07 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		o_hash(t_conv_obj *obj)
{
	char	*new;

	if (!obj->hash || !((obj->con_typ == 'o') || (obj->con_typ == 'O'))
		|| !ft_strcmp(obj->str, "0"))
		return ;
	new = (char *)ft_memalloc(ft_strlen(obj->str) + 2);
	new[0] = '0';
	ft_strcpy(new + 1, obj->str);
	free(obj->str);
	obj->str = new;
}

void			o_func(t_conv_obj *obj, va_list args)
{
	int		n;

	free(obj->str);
	star_args(obj, args);
	if (obj->con_typ == 'o' || obj->con_typ == 'O')
		n = 8;
	else if (obj->con_typ == 'x' || obj->con_typ == 'X')
		n = 16;
	else
		n = 2;
	casting(obj, args, n);
	if (ft_strlen(obj->str) == 0)
		return ;
	o_hash(obj);
	if (!((obj->con_typ == 'o' || obj->con_typ == 'O') && obj->prec == 0))
		d_precision(obj);
	else if (ft_atoi(obj->str) == 0 && obj->prec == 0 && obj->hash == 0)
		obj->str = ft_strdup("");
	x_hash(obj);
	d_width(obj);
	x_hash_alt(obj);
}

void			big_o_func(t_conv_obj *obj, va_list args)
{
	ft_strcpy(obj->len_f, "l");
	o_func(obj, args);
	return ;
}

void			casting(t_conv_obj *obj, va_list args, int n)
{
	if (!ft_strcmp(obj->len_f, "l"))
		obj->str =
			ft_itoa_base((unsigned long)va_arg(args, unsigned long long), n);
	else if (!ft_strcmp(obj->len_f, "ll"))
		obj->str = ft_itoa_base(
			(unsigned long long)va_arg(args, unsigned long long), n);
	else if (!ft_strcmp(obj->len_f, "j"))
		obj->str = ft_itoa_base(va_arg(args, unsigned long), n);
	else if (!ft_strcmp(obj->len_f, "z"))
		obj->str = ft_itoa_base(va_arg(args, unsigned long), n);
	else if (!ft_strcmp(obj->len_f, "hh"))
		obj->str = ft_itoa_base((unsigned char)va_arg(args, unsigned int), n);
	else if (!ft_strcmp(obj->len_f, "h"))
		obj->str = ft_itoa_base((unsigned short)va_arg(args, unsigned int), n);
	else if (!ft_strlen(obj->len_f))
		obj->str = ft_itoa_base(va_arg(args, unsigned int), n);
}
