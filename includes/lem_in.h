/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:09:57 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/07 21:47:29 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "ft_printf.h"

typedef struct		s_lemd
{
	char			*name;
	char			**connections;
}					t_lemd;

typedef struct		s_path
{
	char			*name;
	int				p_len;
	s_path			*nx_node;
	s_path			*nx_path;
}					t_path;


#endif