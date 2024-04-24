#include "fractol.h"
# include <stdio.h>

void mandelbrot(var_t *fractol);


// #include <stdio.h>

// uint32_t teal_lightning(uint32_t count) {
//     // TEAL LIGHTNING color palette
//     uint32_t color;
//     uint32_t palette_size = 10; // Number of colors in the palette

//     // Determine color based on count
//     if (count < MAX_ITER * 1 / palette_size) {
//         color = 0x000000;   // Black
//     } else if (count < MAX_ITER * 2 / palette_size) {
//         color = 0x0E3870;   // Dark Blue
//     } else if (count < MAX_ITER * 3 / palette_size) {
//         color = 0x1E66B8;   // Blue
//     } else if (count < MAX_ITER * 4 / palette_size) {
//         color = 0x2890D8;   // Light Blue
//     } else if (count < MAX_ITER * 5 / palette_size) {
//         color = 0xB4FFF0;   // Teal
//     } else if (count < MAX_ITER * 6 / palette_size) {
//         color = 0xFFFFFF;   // White
//     } else if (count < MAX_ITER * 7 / palette_size) {
//         color = 0xFFB464;   // Orange
//     } else if (count < MAX_ITER * 8 / palette_size) {
//         color = 0xB42828;   // Dark Red
//     } else if (count < MAX_ITER * 9 / palette_size) {
//         color = 0x800000;   // Red
//     } else {
//         color = 0x3C0000;   // Dark Brown
//     }

//     return color;
// }



int	key_hook(int keysym, void *param)
{
    var_t   *fractol;

    fractol = (var_t *)param;
    if (keysym == 8){
        fractol->color += 5;
        mandelbrot(fractol);

    }
	return 0;

}

void    evant_init(var_t    *fractol)
{
        mlx_hook(fractol->win,2 ,1L<<0, key_hook,fractol);
}
void	my_mlx_pixel_put( t_imag img,int x, int y, int color)
{
	int	offset;

	offset = (y * img.line_length) + (x * (img.bits_per_pixel / 8));
	*(int *)(img.addr + offset) = color;
}
double map(double unscaled_num,double min,double max ,double olmin,double oldmax)
{
	return((max - min) * (unscaled_num - olmin) / (oldmax - olmin) + min);
}
int equations(double real,double imag)
{
	double Zr;
	double Zi;
	double  tmp;
	int i;
	int color;

	Zi = 0.0;
	Zr = 0.0;
	i = 0;

	while(Zi*Zi + Zr*Zr <= 4 && i < MAX_iter )
	{
		tmp = Zr * Zr - Zi * Zi + real;
		Zi  = 2 * Zi * Zr + imag;
		Zr = tmp;
		i++;
	}

	return (i);
}
      


void mandelbrot(var_t *fractol) {
    int x;
    int y;
    int color;
    double real;
    double imag;
    y = 0;

    while (y < Y) {
        x = 0;
        while (x < X) {
            real = map(x, -2, 2, 0, X);
            imag = map(y, +2, -2, 0, Y);
            // printf("real = %f, imag = %f\n", real, imag);
            color = equations(real, imag);
            color = color * fractol->color / 4;
            my_mlx_pixel_put(fractol->img, x, y, color ) ;
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
void fractol_conection(var_t *fractol)
{
    fractol->mlx = mlx_init();
    if(!fractol->mlx)
        ft_putstr_fd("9lawi hada",2);
    fractol->win = mlx_new_window(fractol->mlx,X,Y,"fractol");
    if(!fractol->win)
    {
        ft_putstr_fd("rtfm",2);
        free(fractol->mlx);
        exit(1);
    }
    fractol->img.img = mlx_new_image(fractol->mlx,X,Y);
    if(!fractol->img.img)
    {
        mlx_destroy_window(fractol->mlx,fractol->win);
        ft_putstr_fd("rtfm",2);
        free(fractol->mlx);
        exit(1);
    }
    fractol->img.addr = mlx_get_data_addr(fractol->img.img,
                                                &fractol->img.bits_per_pixel,
                                                &fractol->img.line_length,
                                                &fractol->img.endian);
    fractol->color = 4110;
    mandelbrot(fractol)  ;                                              
    evant_init(fractol);
    mlx_loop(fractol->mlx);
}
    