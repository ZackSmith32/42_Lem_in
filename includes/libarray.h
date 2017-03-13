/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libarray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 23:12:42 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/11 17:16:43 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBARRAY_H
# define LIBARRAY_H

# include "libft.h"

int		ft_pusharr(int **a, int num, int len);
int		ft_appendarr(int **a, int num, int len);
int		ft_poparr(int **a, int len);

int		ft_pushstr(char ***tab, char *ptr);
char	*ft_popstr(char **tab);
void	ft_freetab(char **tab);
int		ft_tablen(char **tab);
void	ft_deltabi(char ***tab, size_t index);


#endif