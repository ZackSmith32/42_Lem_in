/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:09:57 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/22 14:34:31 by zsmith           ###   ########.fr       */
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

typedef struct		s_path
{
	char			*name;
	int				len;
	struct s_path	*n_node;
	struct s_path	*n_path;
}					t_path;

extern int g_verbose_flag;

/*
**	b_parse
*/
int					parse();

/*
**	g_constructors
*/
t_lemd				*data_constructor(char *name, char **connections);
t_path				*path_constructor(char *name, int len, t_path *n_node, 
						t_path *n_path);

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
void			print_lemd(t_vect *nodes);
void			print_vect_char(t_vect *data);
t_lemd			*return_match(t_vect *nodes, char *name);


/*
**	l_make_connections
*/
int		make_connections(t_vect *data, t_vect *nodes);

/*
**	m_free_vect
*/
void		free_vector_nodes(t_vect *nodes);




#endif