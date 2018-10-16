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

all:
	@make -C libft/
	@make -C p_swap/

clean:
	@make clean -C libft/
	@make clean -C p_swap/

fclean:
	@make fclean -C libft/
	@make fclean -C p_swap/	

re: fclean all

again: re
	@make clean

.PHONY : all, re, clean, fclean, again
