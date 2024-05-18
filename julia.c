#include "fractol.h"



int julia_equations(double Zr, double Zi, double Cr, double Ci, int MAX_iter)
{
    double tmp;
    int i;
    double t;

    i = 0;
    while (Zi * Zi + Zr * Zr <= 4 && i < MAX_iter)
    {
        tmp = Zr * Zr - Zi * Zi + Cr;
        Zi = 2 * Zi * Zr + Ci;
        Zr = tmp;
        i++;
    }
    if (i == MAX_iter)
        return COLOR_GOLD - (int)Zr;
    t = (double)i / (double)MAX_iter; 
    int red = (int)(9 * (1 - t) * t * t * t * 255); 
    int green = (int)(15 * (1 - t) * (1 - t) * t * t * 255); 
    int blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); 
     return (red << 16) | (green << 8) |  blue;
}
void julia(var_t *fractol, double Cr, double Ci)
{
    int x;
    int y;
    double Zr;
    double Zi;
    int color;

    mlx_clear_window(fractol->mlx, fractol->win);
    y = 0;
    while (y < Y)
    {
        x = 0;
        while (x < X)
        {
            Zr = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx, X);
            Zi = map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty, Y);
            color = julia_equations(Zr, Zi, Cr, Ci, fractol->MAX_iter);
            my_mlx_pixel_put(fractol->img, x, y, color + fractol->color);
            x++;
        }
        y++;
    }

    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}



