# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calamber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 11:20:37 by calamber          #+#    #+#              #
#    Updated: 2018/09/17 12:31:08 by calamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../push_swap

SRC = main.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

LIB = ../libft/libft.a

INC = -I ../includes/

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	make re -C ../libft/
	gcc $(FLAGS) $(INC) $(OBJ) $(LIB) -o $(NAME)

$(OBJ):
	@$(CC) $(FLAGS) -c $(SRC_POS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

again: re
	@make clean

.PHONY : all, re, clean, fclean, again
