/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__pop2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:00:51 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/20 15:11:33 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pop_length(t_conv_obj *obj, char **sentinel)
{
	if (**sentinel == 'h' && (*sentinel)[1] == 'h')
	{
		ft_strcpy(obj->len_f, "hh");
		(*sentinel)++;
	}
	else if (**sentinel == 'h')
		ft_strcpy(obj->len_f, "h");
	if (**sentinel == 'l' && (*sentinel)[1] == 'l')
	{
		ft_strcpy(obj->len_f, "ll");
		(*sentinel)++;
	}
	else if (**sentinel == 'l')
		ft_strcpy(obj->len_f, "l");
	if (**sentinel == 'j')
		ft_strcpy(obj->len_f, "j");
	if (**sentinel == 'z')
		ft_strcpy(obj->len_f, "z");
	if (ft_strc(g_flag_length, **sentinel))
		(*sentinel)++;
}

void	pop_con(t_conv_obj *obj, char **sentinel)
{
	int		i;
	int		num_funcs;

	i = 0;
	num_funcs = 16;
	while (i < num_funcs)
	{
		if (g_func_arr[i].f_nm == **sentinel)
		{
			obj->con_typ = **sentinel;
			obj->f = g_func_arr[i].f;
			(*sentinel)++;
			break ;
		}
		i++;
	}
	if (i == num_funcs && sentinel[0][0] != '\0')
	{
		obj->con_typ = **sentinel;
		obj->f = g_func_arr[num_funcs - 1].f;
		(*sentinel)++;
	}
}

void	pop_parse(t_conv_obj *obj, char **sentinel)
{
	char	*hack;

	hack = ft_strdup("dDxXiuUpsSoO");
	if (obj->minus == 1)
		obj->zero = 0;
	if (obj->plus == 1)
		obj->space = 0;
	(*sentinel)--;
	if (obj->prec != -1 && !(obj->con_typ == 'c'
		|| obj->con_typ == 'C' || obj->con_typ == 's' || obj->con_typ == 'S'
		|| obj->con_typ == '%'))
		obj->zero = 0;
	if (!ft_strchr(hack, **sentinel) && obj->prec == 0)
		obj->zero = 1;
	(*sentinel)++;
	free(hack);
}

int		star_check(t_conv_obj *obj, char **sentinel)
{
	if (**sentinel == '*')
	{
		obj->p_star = 1;
		(*sentinel)++;
		return (1);
	}
	return (0);
}

void	pop_color(t_conv_obj *obj, char **sentinel)
{
	char	*color;
	int		i;

	if (**sentinel == '%')
		(*sentinel)++;
	else
		return ;
	if (**sentinel != '@')
		return ;
	(*sentinel)++;
	i = 0;
	while ((*sentinel)[i] != '@')
		i++;
	color = (char *)ft_memalloc(sizeof(char) * (i + 1));
	ft_strncpy(color, (*sentinel), i);
	color[i + 1] = '\0';
	(*sentinel) += (i + 1);
	// obj->color = ft_strdup(color);
	obj->color = color;
}
