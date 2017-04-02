# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 16:32:25 by zsmith            #+#    #+#              #
#    Updated: 2017/03/22 11:58:19 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FLAGS	=	-Wall -Wextra -Werror
CFILES	=	ft_printf.c			\
			funx__flag.c		\
			funx__help.c		\
			funx__list.c		\
			funx__pop.c			\
			funx__pop2.c		\
			funx__wide.c		\
			funx_d.c			\
			funx_b.c			\
			funx_o.c			\
			funx_pi.c			\
			funx_s.c			\
			funx_c.c			\
			funx_u.c			\
			funx_x.c			\
			glob.c				\

SRCDIR  =	srcs/
OBJDIR	=	obj/
HDIR	=	includes/
OFILES	=	$(addprefix $(OBJDIR), $(CFILES:.c=.o))

.PHONY: all $(NAME) main complib clean flcean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	ar rc $@ $(OFILES)

clean:
	@ /bin/rm -f $(OFILES)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all