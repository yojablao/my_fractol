# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:46:43 by yojablao          #+#    #+#              #
#    Updated: 2024/05/23 10:16:02 by yojablao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = include/libft
MLX_PATH = include/minilibx

SRC_DIR = project
OBJ_DIR = obj
INCLUDE_DIR = include
HEAD = project/fractol.h

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LIBFT = $(LIBFT_PATH)/libft.a

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) 
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -lmlx -framework OpenGL -framework AppKit

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -I$(MLX_PATH) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	rm -r $(OBJ_DIR)


fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re