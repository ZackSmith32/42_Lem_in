/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_parse_ant_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:30:32 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/27 11:02:14 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parse_ant_count(t_vect *data, int *ant_count)
{
	char 		*ant_count_str;
	long long	ant_count_l;

	ant_count_str = *((char **)v_item(data, 0));
	if (!ft_isnum(ant_count_str))
		return (0);
	else
		ant_count_l = ft_atol(ant_count_str);
	if (ant_count_l > INT_MAX || ant_count_l < INT_MIN)
		return (0);
	else
	{
		free(ant_count_str);
		v_remove(data, 0);
		*ant_count = (int)ant_count_l;
		return (1);
	}
}
