# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 23:11:31 by zsmith            #+#    #+#              #
#    Updated: 2017/03/29 19:44:56 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in
FLAGS	=	-c -Wall -Wextra -Werror
FSAN	=	#-fsanitize=address -g
CFILES	=	a_lem_in.c					\
			b_parse.c					\
			c_find_routes.c				\
			d_find_routes_helpers.c		\
			e_print_hq.c				\
			f_requirements_output.c 	\
			h_parse_ant_count.c			\
			i_parse_comments.c			\
			j_make_nodes.c				\
			k_print.c					\
			l_make_connections.c		\
			m_free_vect.c				\
			z_globals.c					\
			
			# test_mallocwrap.c	\

LIBS	=	libft/libft/libft.a			\
			libftprintf/libftprintf.a	\
			libvect/libvect.a			\
			
SRCDIR  =	srcs/
OBJDIR	=	obj/
HDIR	=	includes/
LIBDIR  =	libdir/
OFILES	=	$(addprefix $(OBJDIR), $(CFILES:.c=.o))
LIBFILES=	$(addprefix $(LIBDIR), $(LIBS))

.PHONY: all $(NAME) clean flcean re

all: libs $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	gcc  $(FLAGS) $< -o $@ $(FSAN)

$(NAME): $(OFILES)
	gcc $(FSAN) $(OFILES) -o $@ -I $(HDIR) -L. $(LIBFILES)
	
libs:
	make -C libdir/libft/libft/
	make -C libdir/libftprintf/
	make -C libdir/libvect/

clean:
	/bin/rm -f $(OFILES)
	make clean -C libdir/libft/libft/
	make clean -C libdir/libftprintf/
	make clean -C libdir/libvect/


fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libdir/libft/libft/
	make fclean -C libdir/libftprintf/
	make fclean -C libdir/libvect/

re: fclean all
