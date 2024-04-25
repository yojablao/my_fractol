#include "fractol.h"


int main(int c ,char **v)
{


	var_t	fractol;
	if(c == 2 && ft_strncmp(v[1],"Mandelbrot",10) == 0 ||
		c == 4 && ft_strncmp(v[1],"Julia",5) == 0)
	{
		fractol_conection(&fractol);
	}
	else
	{
		ft_putstr_fd("fail",2);
		exit(1);
	}
}
