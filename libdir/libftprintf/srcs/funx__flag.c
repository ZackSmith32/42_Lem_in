/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:59:38 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 21:23:09 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	plus_func(t_conv_obj *obj)
{
	char	*new_str;
	char	a;
	int		i;

	if (obj->plus == 0)
		return ;
	i = 0;
	if (ft_strchr(obj->str, '-'))
		return ;
	else
		a = '+';
	new_str = ft_memalloc(ft_strlen(obj->str) + 2);
	new_str[0] = a;
	ft_strcat(new_str, obj->str);
	free(obj->str);
	obj->str = new_str;
}

void	space_flag(t_conv_obj *obj)
{
	char	*new_str;

	if (obj->space == 0)
		return ;
	if (ft_strchr(obj->str, '-'))
		return ;
	if (obj->str[0] == '0' || obj->str[0] == ' ')
		obj->str[0] = ' ';
	else
	{
		new_str = ft_memalloc(ft_strlen(obj->str) + 2);
		new_str[0] = ' ';
		ft_strcat(new_str, obj->str);
		free(obj->str);
		obj->str = new_str;
	}
}

void	star_args(t_conv_obj *obj, va_list args)
{
	int		i;

	if (obj->w_star)
	{
		i = va_arg(args, int);
		if (i < 0)
		{
			i = i * -1;
			obj->minus = 1;
			obj->zero = 0;
		}
		if (obj->width == 0)
			obj->width = i;
	}
	if (obj->p_star)
	{
		obj->prec = va_arg(args, int);
		if (obj->prec < 0)
			obj->prec = -1;
	}
}

int		ft_strc(char *str, char c)
{
	int		i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		utf_len(wchar_t *wide)
{
	int		i;
	int		j;

	if (!wide)
		return (0);
	i = 0;
	j = 0;
	while (wide[i] != 0)
	{
		if (wide[i] <= 0x78)
			j += 1;
		else if (wide[i] <= 0x1fff)
			j += 2;
		else if (wide[i] <= 0xffff)
			j += 3;
		else
			j += 4;
		i++;
	}
	return (j);
}
