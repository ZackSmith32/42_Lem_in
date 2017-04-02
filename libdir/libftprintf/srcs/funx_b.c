/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 23:10:57 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/14 00:10:57 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Note on binary:
**	> binary is unsigned
**	> width is ignored.  Width will be the appropriate size given input
**		size flage, (i.e. 4 for int, 1 for char etc.).
**	> binary does not have 0 flag
**	> binary does not have precision
**	> width contraints can be bypassed by useing wildcard character
**		which is applied after this stage, though is not recommended
*/

static void	b_func_setwidth(t_conv_obj *obj)
{
	if (!ft_strcmp(obj->len_f, "ll") || !ft_strcmp(obj->len_f, "l"))
		obj->width = 64;
	if (!ft_strlen(obj->len_f))
		obj->width = 32;
	if (!ft_strcmp(obj->len_f, "h"))
		obj->width = 16;
	if (!ft_strcmp(obj->len_f, "hh"))
		obj->width = 8;
}

void		b_func(t_conv_obj *obj, va_list args)
{
	char	*new;
	int		i;
	int		j;

	b_func_setwidth(obj);
	obj->prec = -1;
	obj->zero = 1;
	o_func(obj, args);
	new = (char *)ft_memalloc(obj->width + (obj->width / 8) - 1);
	j = 0;
	i = 0;
	while (obj->str[i] != '\0')
	{
		if (i % 8 == 0 && i != 0)
			new[j++] = ' ';
		new[j] = obj->str[i];
		j++;
		i++;
	}
	new[j] = '\0';
	free(obj->str);
	obj->str = new;
}
