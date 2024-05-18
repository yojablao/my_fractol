#include "fractol.h"
int burning_ship(double real, double imag, int MAX_iter) 
{
    double Zr = 0.0;
    double Zi = 0.0;
    double tmp;
    int i;
    double t;
    int time_shift;

    i = 0;
    while (Zi * Zi + Zr * Zr <= 4 && i < MAX_iter) {
        tmp = Zr * Zr - Zi * Zi + real;
        Zi = fabs(2 * Zi * Zr) + imag;
        Zr = fabs(tmp);
        i++;
    }
    if (i == MAX_iter)
        return COLOR_GOLD ;
    t = (double)i / (double)MAX_iter;
    int red = (int)(9 * (1 - t) * t * t * t * 255);
    int green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (red << 16) | (green << 8) | blue;
}

void draw_burning_ship(var_t *fractol)
{
    int x;
    int y;
    double real;
    double imag;
    int color;

    mlx_clear_window(fractol->mlx,fractol->win);
    y = 0;
    while (y < Y)
    {
        x = 0;
        while (x < X)
        {
            real = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx, X);
            imag = map(y, -2 * fractol->cor.scaling + fractol->cor.shefty , 2 * fractol->cor.scaling + fractol->cor.shefty, Y);
            color = burning_ship(real, imag, fractol->MAX_iter);
            my_mlx_pixel_put(fractol->img, x, y, color + fractol->color);
            x++;
        }
        y++;
    }

    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
