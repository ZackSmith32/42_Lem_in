/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:12:29 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/17 18:50:41 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			pop_str(t_conv_obj *obj, char **str)
{
	int		i;
	int		j;
	char	*p_str;

	i = 0;
	while (str[0][i] != '%' && str[0][i] != '\0')
		i++;
	p_str = (char *)malloc(i + 1);
	j = 0;
	while (j < i)
	{
		p_str[j] = **str;
		(*str)++;
		j++;
	}
	p_str[j] = '\0';
	free(obj->str);
	obj->str = p_str;
	obj->con_typ = 't';
}

void			pop_flags(t_conv_obj *obj, char **sentinel)
{
	while (ft_strc(g_flag_norm, **sentinel) != 0)
	{
		if (**sentinel == '-')
			obj->minus = 1;
		if (**sentinel == '+')
			obj->plus = 1;
		if (**sentinel == '#')
			obj->hash = 1;
		if (**sentinel == ' ')
			obj->space = 1;
		if (**sentinel == '0')
			obj->zero = 1;
		(*sentinel)++;
	}
}

static int		pop_width2(t_conv_obj *obj, char **sentinel)
{
	if (**sentinel == '*')
	{
		obj->w_star = 1;
		obj->width = 0;
		(*sentinel)++;
		return (1);
	}
	return (0);
}

void			pop_width(t_conv_obj *obj, char **sentinel)
{
	int		i;
	char	*holder;

	i = 0;
	pop_width2(obj, sentinel);
	while (ft_isdigit(sentinel[0][i]))
		i++;
	holder = ft_memalloc(i + 1);
	i = 0;
	while (ft_isdigit(**sentinel))
	{
		holder[i] = **sentinel;
		(*sentinel)++;
		i++;
	}
	holder[i] = '\0';
	i = ft_atoi(holder);
	free(holder);
	obj->width = i;
	pop_width2(obj, sentinel);
}

void			pop_precision(t_conv_obj *obj, char **sentinel)
{
	int		i;
	char	*holder;

	if (**sentinel == '.')
		(*sentinel)++;
	else
		return ;
	if (star_check(obj, sentinel))
		return ;
	i = 0;
	while (ft_isdigit(sentinel[0][i]))
		i++;
	holder = (char *)ft_memalloc(i + 1);
	i = 0;
	while (ft_isdigit(**sentinel))
	{
		holder[i] = **sentinel;
		(*sentinel)++;
		i++;
	}
	holder[i] = '\0';
	i = ft_atoi(holder);
	free(holder);
	obj->prec = i;
}
