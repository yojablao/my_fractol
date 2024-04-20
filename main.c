#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "src/libft.h"
#include <math.h>

#define WIDTH 700
#define HEIGHT 600
#define MAX_ITER 1500

typedef struct s_fract
{
	void *mlx;
    void *win;
}	f_t;

// Function to check if a point (x, y) is in the Mandelbrot set
int mandelbrot(double real, double imag) {
    double z_real = 0, z_imag = 0, temp;
    int iter = 0;
    //z+1 = z^2 + c
    //==>  ()
    //real^2 
    while (z_real * z_real + z_imag * z_imag <=2 && iter < MAX_ITER ) {
        temp = z_real*z_real- z_imag*z_imag + real;
        z_imag = 2 * z_real * z_imag + imag;
        z_real = temp;
        iter++;
    }
    
    return iter;
}

// Function to draw the Mandelbrot set
void draw_mandelbrot(void *mlx, void *win) {
    double real_min = -2.0*0.1, real_max = 2.0 * 0.1;
    double imag_min = -2.0* 0.1, imag_max = 2.0 *0.1;
    
    int y = 0;
    while (y < HEIGHT) {
        int x = 0;
        while (x < WIDTH) {
            double real = real_min + (real_max - real_min) * x / (double)WIDTH;
            double imag = imag_min + (imag_max - imag_min) * y / (double)HEIGHT;
            
            int color = mandelbrot(real, imag);
            
            // Set pixel color based on the number of iterations to escape
            mlx_pixel_put(mlx, win, x, y, color);
            
            x++;
        }
        y++;
    }
}

int	key_hook(int keycode, void *param)
{
    ft_putnbr_fd(keycode,1);
    ft_putchar_fd('\n',1);
	return 0;

}
void    evant_init(f_t    *fractol)
{
        mlx_hook(fractol->win,2 ,1L<<0, key_hook,fractol);
}


int main() {

	f_t	mlx;

    mlx.mlx = mlx_init();
    if (!mlx.mlx) {
        printf("Error: couldn't initialize MiniLibX\n");
        return 1;
    }
    
    mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
    if (!mlx.win) {
        printf("Error: couldn't create window\n");
        return 1;
    }
    
    draw_mandelbrot(mlx.mlx, mlx.win);
	evant_init(&mlx);

    
    mlx_loop(mlx.mlx);
    
    return 0;
}














// #include <mlx.h>
// #include <libc.h>

// int	main(int c,char **v)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	if(c != 6)
// 		return 0;
// 	int toll = atoi(v[2]);
// 	int lard = atoi(v[3]);
// 	int i , j;
// 	i = lard * 0.1;
// 	j = toll * 0.1;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx,toll, lard, v[1]);
// 	while (j < toll * 0.9)
// 	{
// 		i = lard * 0.1;
// 		while(i < lard * 0.9)
// 		{
// 			if(i >= lard *0.9)
// 				break;
// 			mlx_pixel_put(mlx,mlx_win,toll - i, lard - j,rand()  % 0x1000000);
// 			i++;
// 		}
// 		j++;
// 	}
// 	mlx_string_put(mlx,mlx_win,toll *0.009 ,lard *0.009,0xff0000,"hii beatsh");
	
	// while (j < atoi(v[4]))
	// {
	// 	i = 0;
	// 	while(i < atoi(v[5]))
	// 	{
	// 		mlx_pixel_put(mlx,mlx_win,toll / 2 +i, lard/ 2 +j,rand()  % 0x1000000);
	// 		i++;
	// 	}
	// 	j++;

	// }
	// i = 1;
	// while (i < 500)
	// {
	// 	mlx_pixel_put(mlx,mlx_win,500-i,500,0xFFFF00);
	// 	i++;

	// }

	// i = 0;
	// while(j<500)
	// {
	// 	mlx_pixel_put(mlx,mlx_win,500,500-j,0xFFFF00);
	// 	j++;
	// }
	// j = 1;
	// while(j<500)
	// {
	// 	mlx_pixel_put(mlx,mlx_win,500,500+j,0xFFFF00);
	// 	j++;
	// }
	
// mlx_loop(mlx);

// }