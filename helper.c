#include "fractol.h"

void    reset(var_t *fractol)
{
    fractol->color = 1;
    fractol->MAX_iter = 50;
    fractol->cor.scaling = 1;
    fractol->cor.sheftx = 0;
    fractol->cor.shefty = 0;
}
void ft_color(int iteration, int *red, int *green, int *blue) {
    *red = (iteration * 10) % 250;
    *green = (iteration * 10) % 250;
    *blue = (iteration * 2) % 250;
}

void	my_mlx_pixel_put( t_imag img,int x, int y, int color)
{
	int	offset;

	offset = (y * img.line_length) + (x * (img.bits_per_pixel / 8));
	*(int *)(img.addr + offset) = color;
}

double map(double unscaled_num,double min,double max ,double oldmax)
{
	return((max - min) * (unscaled_num - 0) / (oldmax - 0) + min);
}

int equations(double real, double imag, int MAX_iter, int color_shift)
{
    double Zr;
    double Zi;
    double tmp;
    int i;
    double t;
    int time_shift;

    Zi = 0.0;
    Zr = 0.0;
    i = 0;
    while (Zi * Zi + Zr * Zr <= 4 && i < MAX_iter)
    {
        tmp = Zr * Zr - Zi * Zi + real;
        Zi = 2 * Zi * Zr + imag;
        Zr = tmp;
        i++;
    }
    if (i == MAX_iter)
        return COLOR_HOT_PINK - (int)real;
    time_shift = color_shift + i;
    
    // Interpolate between different neon colors based on the number of iterations and time shift
    t = (double)time_shift / (double)MAX_iter; // Calculate interpolation factor
    int red = (int)(9 * (1 - t) * t * t * t * 255); // Neon pink
    int green = (int)(15 * (1 - t) * (1 - t) * t * t * 255); // Neon blue-green
    int blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); // Neon purple
     return (red << 16) | (green << 8) |  blue;
}

void mandelbrot(var_t *fractol)
{
    int x;
    int y;
    double real;
    double imag;
    int  color_shift =0 ;
    int color;

    mlx_clear_window(fractol->mlx,fractol->win);
    y = 0;
    while (y < Y)
    {
        x = 0;
        while (x < X)
        {
            real = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx, X);
            imag = map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty, Y);
            color = equations(real, imag, fractol->MAX_iter,color_shift);
            my_mlx_pixel_put(fractol->img, x, y, color + fractol->color);
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
    reset(fractol);     
    mandelbrot(fractol);                                    
    evant_init(fractol);
    mlx_loop(fractol->mlx);
}
    