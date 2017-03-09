# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2017/03/09 14:19:18 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in
FLAGS	=	-c -Wall -Wextra -Werror
CLEAKS	=	test_mallocwrap.c
CFILES	=	a_lem_in.c			\
			b_parse.c			\
			g_constructors.c	\
			i_make_graph.c		\
			j_make_nodes.c		\

SRCDIR  =	srcs/
HDIR	=	includes/
LIBDIR  =	libdir/

.PHONY: all $(NAME) clean flcean re

all: $(NAME)

$(NAME): 
	gcc $(addprefix $(SRCDIR), $(CFILES)) -o $@ -I $(HDIR) 	\
		-L. $(addprefix $(LIBDIR), 'libft.a' 'libftprintf.a' 'libvector.a') 
	
libft:
	make re -C /nfs/2016/z/zsmith/libft_dir/libft
	cp /nfs/2016/z/zsmith/libft_dir/libft/libft.h ./includes

printf:
	make re -C /nfs/2016/z/zsmith/printf
	cp /nfs/2016/z/zsmith/printf/includes/ft_printf.h ./includes

vector:
	make re -C /nfs/2016/z/zsmith/vector
	cp /nfs/2016/z/zsmith/vector/includes/vector.h ./includes

clean:
	/bin/rm -f $(addprefix $(SRCDIR), $(OFILES))

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all






#	Things needed to be done before submission	\
	> copy lib dirs into lib folder				\
		> update make files if necessary		\
		> remove headers						\
	> make the compile lib commands mandatory	\
	> add a make -C to clean libs