/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:31:23 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/13 12:31:19 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT_H
# define VECT_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct			s_vect
{
	size_t				cap;
	size_t				len;
	size_t				units;
	size_t				data_size;
	void				*a;
}						t_vect;

t_vect		*v_new(size_t len, size_t data_size);
void		v_increase(t_vect *head);
void		v_insert(t_vect *head, size_t i, void *data);
void		*v_item(t_vect *vect, size_t index);
void		v_remove(t_vect *vect, size_t i);


#endif