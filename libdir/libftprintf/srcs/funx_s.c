/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:52:51 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 20:24:28 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ret_null(t_conv_obj *obj)
{
	char	*a;

	a = ft_strdup("(null)");
	obj->str = a;
}

void		s_prec_long(t_conv_obj *obj, char *s)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i + j <= obj->prec)
	{
		i += j;
		j = 0;
		if ((unsigned char)s[i] <= 0x7f)
			j = 1;
		else if ((unsigned char)s[i] <= 0xdf)
			j = 2;
		else if ((unsigned char)s[i] <= 0xef)
			j = 3;
		else
			j = 4;
	}
	ft_strncpy(obj->str, s, i);
}

void		s_precision(t_conv_obj *obj, char *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	if (ft_strcmp(obj->len_f, "l") == 0 &&
		obj->con_typ == 'S' && obj->prec != -1)
		s_prec_long(obj, s);
	else if (obj->prec != -1)
		ft_strncpy(obj->str, s, obj->prec);
	else
		ft_strcpy(obj->str, s);
}

static char	*s_func_helper(wchar_t *w)
{
	char	*test;
	int		i;
	char	*s;

	s = (char *)ft_memalloc(utf_len(w));
	i = -1;
	while (w[++i] != 0)
	{
		test = s_wide(w[i]);
		ft_strcat(s, test);
		free(test);
	}
	return (s);
}

void		s_func(t_conv_obj *obj, va_list args)
{
	char	*s;
	wchar_t	*w;

	free(obj->str);
	star_args(obj, args);
	if (!ft_strcmp(obj->len_f, "l"))
	{
		w = va_arg(args, wchar_t *);
		if (w == NULL)
			return (ret_null(obj));
		s = s_func_helper(w);
	}
	else
	{
		s = va_arg(args, char *);
		if (s == NULL && obj->zero != 1)
			return (ret_null(obj));
	}
	obj->str = (char *)ft_memalloc(ft_strlen(s) + 1);
	s_precision(obj, s);
	if (!ft_strcmp(obj->len_f, "l"))
		free(s);
	d_width(obj);
}
