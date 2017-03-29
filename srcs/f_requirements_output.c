/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_requirements_output.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 09:06:50 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/29 10:54:12 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #include "../includes/lem_in.h"

void	req_output(t_vect *nodes, int ants, t_vect *print_connects)
{
	int		i;
	t_lemd	*node;

	ft_printf("%d\n", ants);
	i = 0;
	while (i < nodes->units)
	{
		node = *((t_lemd **)v_item(nodes, i));
		if (node->s_e == 1)
			ft_printf("##start\n");
		if (node->s_e == 2)
			ft_printf("##end\n");
		ft_printf("%s %d %d\n", node->name, node->coordinate_x, 
			node->coordinate_y);
		i++;
	}
	print_str_vect(print_connects);
	printf("\n");
}
