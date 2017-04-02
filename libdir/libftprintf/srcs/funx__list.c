/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funx__list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:32:09 by zsmith            #+#    #+#             */
/*   Updated: 2017/01/02 16:29:04 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_conv_obj	*new_conv_obj(void)
{
	t_conv_obj	*newnew;

	newnew = (t_conv_obj *)ft_memalloc(sizeof(t_conv_obj));
	newnew->len_f = (char *)ft_memalloc(2);
	newnew->prec = -1;
	newnew->str = ft_strdup("*");
	return (newnew);
}

void		ft_lstadd_end(t_conv_obj *start, t_conv_obj *new)
{
	t_conv_obj	*holder;

	if (start == new)
		return ;
	holder = start;
	while (holder->next != NULL)
		holder = holder->next;
	holder->next = new;
}

static int	print_null(int j)
{
	ft_putchar('\0');
	j++;
	return (j);
}

int			ft_putobj(t_conv_obj *t)
{
	int			j;
	t_conv_obj	*k;

	j = 0;
	while (t)
	{
		if (t->color)
			ft_color_on(1, t->color);
		if (t->extra == 1 && t->minus == 1)
			j = print_null(j);
		ft_putstr(t->str);
		j += ft_strlen(t->str);
		if (t->extra == 1 && t->minus == 0)
			j = print_null(j);
		ft_color_on(1, "reset");
		k = t;
		free(t->len_f);
		free(t->color);
		free(t->str);
		t = t->next;
		free(k);
	}
	return (j);
}
