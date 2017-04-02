/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:26:23 by zsmith            #+#    #+#             */
/*   Updated: 2017/01/02 16:29:00 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pop_obj(t_conv_obj *obj, char **sentinel)
{
	if (**sentinel == '%')
	{
		pop_color(obj, sentinel);
		pop_flags(obj, sentinel);
		pop_width(obj, sentinel);
		pop_precision(obj, sentinel);
		pop_length(obj, sentinel);
		pop_con(obj, sentinel);
		pop_parse(obj, sentinel);
	}
	else
		pop_str(obj, sentinel);
	return (1);
}

int		mission_control(char **sentinel, va_list args)
{
	t_conv_obj	*item;
	t_conv_obj	*temp;
	int			i;

	temp = new_conv_obj();
	item = temp;
	i = 0;
	if (**sentinel == 0)
	{
		free(temp->str);
		item->str = ft_strdup("");
	}
	while (sentinel[0][0] != '\0')
	{
		if (i)
			temp = new_conv_obj();
		pop_obj(temp, sentinel);
		if (temp->f)
			(temp->f)(temp, args);
		else if (ft_strchr(temp->str, '*') != NULL)
			temp->str = ft_strdup("");
		ft_lstadd_end(item, temp);
		i++;
	}
	return (ft_putobj(item));
}

int		ft_printf(char *sentinel, ...)
{
	va_list args;

	va_start(args, sentinel);
	return (mission_control(&sentinel, args));
	va_end(args);
	return (0);
}
