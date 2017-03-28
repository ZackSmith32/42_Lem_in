# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2017/03/27 21:47:15 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in
FLAGS	=	-c -Wall -Wextra -Werror
FSAN	=	-fsanitize=address -g
CLEAKS	=	test_mallocwrap.c
CFILES	=	a_lem_in.c				\
			b_parse.c				\
			c_find_routes.c			\
			d_find_routes_helpers.c	\
			e_print_hq.c			\
			h_parse_ant_count.c		\
			i_parse_comments.c		\
			j_make_nodes.c			\
			k_print.c				\
			l_make_connections.c	\
			m_free_vect.c			\
			z_globals.c				\
			test_mallocwrap.c	\
			

LIBS	=	libft.a				\
			libftprintf.a		\
			libarray.a			\
			libvect.a			\
			
SRCDIR  =	srcs/
OBJDIR	=	obj/
HDIR	=	includes/
LIBDIR  =	libdir/
OFILES	=	$(addprefix $(OBJDIR), $(CFILES:.c=.o))
LIBFILES=	$(addprefix $(LIBDIR), $(LIBS))

.PHONY: all $(NAME) clean flcean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	gcc  $(FLAGS) $< -o $@ $(FSAN)

$(NAME): $(OFILES)
	gcc $(FSAN) $(OFILES) -o $@ -I $(HDIR) -L. $(LIBFILES)
	
libft:
	make re -C /nfs/2016/z/zsmith/libft_dir/libft
	cp /nfs/2016/z/zsmith/libft_dir/libft/libft.h ./includes

printf:
	make re -C /nfs/2016/z/zsmith/printf
	cp /nfs/2016/z/zsmith/printf/includes/ft_printf.h ./includes

array:
	make re -C /nfs/2016/z/zsmith/libarray
	cp /nfs/2016/z/zsmith/libarray/includes/libarray.h ./includes

vect:
	make re -C /nfs/2016/z/zsmith/vect
	cp /nfs/2016/z/zsmith/vect/includes/vect.h ./includes

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all






#	Things needed to be done before submission	\
	> copy lib dirs into lib folder				\
		> update make files if necessary		\
		> remove headers						\
	> make the compile lib commands mandatory	\
	> add a make -C to clean libs