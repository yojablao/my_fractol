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


void    close_handler(var_t *fractol)
{
    mlx_clear_window(fractol->mlx,fractol->win);
    perror("0");
    mlx_destroy_image (fractol->mlx,fractol->img.img);
    perror("1");
    mlx_destroy_window(fractol->mlx,fractol->win);
    perror("2");
    free(fractol->mlx);
    exit(0);
}
int	key_hook(int keysym, void *param)
{
    var_t   *fractol;

    fractol = (var_t *)param;
    if (keysym == 8){
        fractol->color += 5;
        mandelbrot(fractol);

    }
    printf("key = %d\n",keysym);
    if(keysym == 34)
    {
        fractol->MAX_iter+= 10;
        mandelbrot(fractol);
    }
    if(keysym == 35)
    {
        fractol->MAX_iter-= 10;
        mandelbrot(fractol);
    }
    if(keysym == 69)
    {
        fractol->cor.scaling *= 1.5;
        mandelbrot(fractol);
    }
    if(keysym == 78)
    {
        fractol->cor.scaling /= 1.5;
        mandelbrot(fractol);
    }
    if(keysym == 124)
    {
        if(fractol->cor.scaling > 10)
            fractol->cor.sheftx += 0.009;
        else
            fractol->cor.sheftx += 0.009;
        mandelbrot(fractol);
    }
    if(keysym == 123)
    {
        if(fractol->cor.scaling > 10.5)
            fractol->cor.sheftx -= 0.009;
        else
            fractol->cor.sheftx -= 0.009;
        mandelbrot(fractol);
    }
    if(keysym == 126)
    {
        if(fractol->cor.scaling > 10)
            fractol->cor.shefty += 0.009;
        else
            fractol->cor.shefty += 0.009;
        mandelbrot(fractol);
    }
    if(keysym == 125)
    {
        if(fractol->cor.scaling > 10)
            fractol->cor.shefty -= 0.009;
        else
            fractol->cor.shefty -= 0.009;
        mandelbrot(fractol);
    }
    if(keysym == 53)
        close_handler(fractol);
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
int equations(double real,double imag,int MAX_iter)
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

	return (i == MAX_iter ? COLOR_GRAY/25 : i);
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
            real = map(x, -2 *fractol->cor.scaling, 2 *fractol->cor.scaling, 0, X)+ fractol->cor.sheftx;
            imag = map(y, +2 *fractol->cor.scaling, -2 *fractol->cor.scaling, 0, Y) + fractol->cor.shefty;
            color = equations(real, imag,fractol->MAX_iter);
            color = color * fractol->color / 8;
             // You can adjust the division to control the lightness
            // Extract RGB components
            int r = (color >> 16) & 0xFF;
            int g = (color >> 8) & 0xFF;
            // int b = color & 0xFF;
            // Decrease intensity by scaling down the RGB components
            r = r * 1.5; // Adjust the multiplier to control the lightness
            g = g * 1.5;
            // b = b * 1.5;
            // Recombine RGB components
            color = (r << 16) + (g << 8)  ;
            my_mlx_pixel_put(fractol->img, x, y, color );
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
    fractol->color = 4112;
    fractol->MAX_iter = 42;
    fractol->cor.scaling = 1;
    fractol->cor.sheftx =0;
    fractol->cor.shefty = 0;
    mandelbrot(&*fractol)  ;                                              
    evant_init(&*fractol);
    mlx_loop(fractol->mlx);
}
    