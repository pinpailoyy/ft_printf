# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: puthai <puthai@student.42bangkok.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 03:44:11 by puthai            #+#    #+#              #
#    Updated: 2024/01/08 03:52:15 by puthai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putnbr_base.c

OBJ = ${SRC:.c=.o}

all:	$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: re clean fclean all
