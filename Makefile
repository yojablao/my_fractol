NAME = fractol

srs = fractol.c helper.c libft.a libmlx.a  julia.c tools.c keys.c burning_ship.c 

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
all: $NAME
