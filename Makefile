# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:46:43 by yojablao          #+#    #+#              #
#    Updated: 2024/05/20 16:46:44 by yojablao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

srs = fractol.c helper.c libft.a libmlx.a  julia.c tools.c keys.c burning_ship.c 

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
all: $NAME
