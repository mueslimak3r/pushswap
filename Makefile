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
	make -C p_swap/

clean:
	make clean -C p_swap/

fclean:
	make fclean -C p_swap/	

re:
	make re -C p_swap/

again: re
	make clean

.PHONY : all, re, clean, fclean, again
