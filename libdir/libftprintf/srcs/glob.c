/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:55:55 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 23:19:56 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *g_flag_norm = "-+# 0";
char *g_flag_length = "hljz";

t_f_list g_func_arr[] = {
	{'s', &s_func},
	{'S', &big_s_func},
	{'p', &p_func},
	{'d', &d_func},
	{'D', &big_d_func},
	{'i', &i_func},
	{'o', &o_func},
	{'O', &big_o_func},
	{'u', &u_func},
	{'U', &big_u_func},
	{'x', &x_func},
	{'X', &big_x_func},
	{'c', &c_func},
	{'C', &big_c_func},
	{'b', &b_func},
	{'%', &non_func}
};
