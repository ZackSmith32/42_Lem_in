/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:09:57 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/24 13:23:15 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "ft_printf.h"
# include "libarray.h"
# include "vect.h"

typedef struct		s_lemd
{
	int				s_e;
	char			*name;
	t_vect			*connections;
}					t_lemd;

extern int g_verbose_flag;

/*
**	b_parse
*/
int				parse(t_vect *nodes);

/*
**	c_find_routes
*/
int		make_routes(t_vect *nodes, t_vect **dist_table);

/*
**	d_find_routes_helpers
*/
t_lemd			*find_start_node(t_vect *nodes);

/*
**	i_parse_comments
*/
int				parse_comments(t_vect *data, t_vect *nodes);

/*
**	j_make_nodes
*/
int				make_nodes(t_vect *data, t_vect *nodes);
int				check_node(char *line);
int				create_node(char *line, t_vect *nodes, int s_e);

/*
**	k_print
*/
void			print_path_of_node(t_vect *curr_table_path, int tabs);
void			print_vect_lemd(t_vect *nodes);
void			print_vect_char(t_vect *data);
void			print_connections(t_vect *connections);


/*
**	l_make_connections
*/
int				make_connections(t_vect *data, t_vect *nodes);
t_lemd			*search_nodes_by_name(t_vect *nodes, char *search_name);

/*
**	m_free_vect
*/
void			free_vector_nodes(t_vect *nodes);




#endif