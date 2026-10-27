# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsarkoez <bsarkoez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/20 16:12:09 by bsarkoez          #+#    #+#              #
#    Updated: 2026/10/27 14:50:57 by bsarkoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc -Wall -Werror -Wextra 
AR		= ar rcs
OBJ		= $(SRC:.c=.o)
RM		= rm -f
SRC 	= ft_printf.c \
		ft_print_char.c \
		ft_print_nbr.c

all		:$(NAME)
$(NAME)	:$(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o		: %.c
		$(CC) -c $< -o $@

clean	: 
		$(RM) $(OBJ)

fclean	:clean
		$(RM) $(NAME) a.out

re		:fclean all

.PHONY	: all clean fclean re