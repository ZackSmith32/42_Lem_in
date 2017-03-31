/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_requirements_output.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 09:06:50 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/29 20:01:20 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #include "../includes/lem_in.h"

void		free_print_connects(t_vect *print_connects)
{
	size_t		i;
	char		*temp;

	i = 0;
	while (i < print_connects->units)
	{
		temp = *((char **)v_item(print_connects, i));
		free(temp);
		i++;
	}
	free(print_connects->a);	
	free(print_connects);

}

void		req_output(t_vect *nodes, int ants, t_vect *print_connects)
{
	size_t	i;
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
	free_print_connects(print_connects);
	ft_printf("\n");
}
