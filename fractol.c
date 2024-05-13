#include "fractol.h"


int main(int c ,char **v)
{


	var_t	fractol;
	if(c == 2 && ft_strncmp(v[1],"Mandelbrot",10) == 0 )
	{
		fractol_conection(&fractol);
		mandelbrot(&fractol);                                    
    	evant_init(&fractol);
   		mlx_loop(&fractol.mlx);
	}
	// else if(c == 4 && ft_strncmp(v[1],"Julia",5) == 0)
	// {
	// 	fractol_conection(&fractol);
	// 	Julia(&fractol);                                    
    // 	evant_init(&fractol);
   	// 	mlx_loop(&fractol.mlx);
	// }
	else
	{
		ft_putstr_fd("fail",2);
		exit(1);
	}

}
