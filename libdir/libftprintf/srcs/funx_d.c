/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:36:17 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 23:51:27 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	big_d_func(t_conv_obj *obj, va_list args)
{
	ft_strcpy(obj->len_f, "l");
	d_func(obj, args);
	return ;
}

void	d_func(t_conv_obj *obj, va_list args)
{
	star_args(obj, args);
	free(obj->str);
	if (!ft_strlen(obj->len_f))
		obj->str = ft_itoa3((int)va_arg(args, int));
	if (!ft_strcmp(obj->len_f, "hh"))
		obj->str = ft_itoa3((char)va_arg(args, int));
	if (!ft_strcmp(obj->len_f, "h"))
		obj->str = ft_itoa3((short)va_arg(args, int));
	if (!ft_strcmp(obj->len_f, "l"))
		obj->str = ft_itoa3((long)va_arg(args, long long));
	if (!ft_strcmp(obj->len_f, "ll"))
		obj->str = ft_itoa3(va_arg(args, long long));
	if (!ft_strcmp(obj->len_f, "j") || !ft_strcmp(obj->len_f, "z"))
		obj->str = ft_itoa3(va_arg(args, unsigned long long));
	d_precision(obj);
	plus_func(obj);
	d_width(obj);
	space_flag(obj);
	return ;
}

void	d_precision(t_conv_obj *obj)
{
	char	*new_str;
	char	*holder;
	int		diff;

	if (!ft_strcmp(obj->str, "0") && obj->prec == 0)
	{
		free(obj->str);
		obj->str = ft_memalloc(1);
		return ;
	}
	if (ft_strchr(obj->str, '-'))
		obj->prec++;
	diff = obj->prec - ft_strlen(obj->str);
	if (diff <= 0)
		return ;
	new_str = (char *)ft_memalloc(obj->prec);
	ft_memset(new_str, 48, (size_t)(obj->prec + 1));
	holder = new_str + diff;
	ft_strcpy(holder, obj->str);
	free(obj->str);
	obj->str = new_str;
	d_width_zero(obj);
}

void	d_width(t_conv_obj *obj)
{
	char	*new_str;
	char	*holder;
	int		diff;

	diff = obj->width - ft_strlen(obj->str);
	if (diff > 0)
	{
		new_str = (char *)ft_memalloc(obj->width + 1);
		ft_memset(new_str, obj->zero == 1 ? 48 : 32, (size_t)(obj->width));
		if (!obj->minus)
			holder = new_str + diff;
		else
			holder = new_str;
		ft_strncpy(holder, obj->str, ft_strlen(obj->str));
		free(obj->str);
		obj->str = new_str;
		if (obj->zero == 1 && (obj->con_typ == 'd' || obj->con_typ == 'D') &&
			(obj->plus == 1 || ft_strchr(obj->str, '-')))
			d_width_zero(obj);
	}
}

void	d_width_zero(t_conv_obj *obj)
{
	int		i;

	i = 0;
	while (obj->str[i] != '-' && obj->str[i] != '+' && obj->str[i] != '\0')
		i++;
	if (obj->str[i] == '\0')
		return ;
	obj->str[0] = obj->str[i];
	obj->str[i] = '0';
}
