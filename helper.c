#include "fractol.h"


int equations(double real, double imag, int MAX_iter)
{
    double Zr;
    double Zi;
    double tmp;
    int i;
    double t;

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
    // Interpolate between different neon colors based on the number of iterations and time shift
    t = (double)i / (double)MAX_iter; // Calculate interpolation factor
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
            color = equations(real, imag, fractol->MAX_iter);
            my_mlx_pixel_put(fractol->img, x, y, color + fractol->color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
    