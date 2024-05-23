/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 06:05:40 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/23 06:05:41 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int equations(double real, double imag, var_t fractol)
{
    double Zr;
    double Zi;
    double tmp;
    int i;

    Zi = 0.0;
    Zr = 0.0;
    i = 0;
    while (Zi * Zi + Zr * Zr <= 4 && i < fractol.MAX_iter)
    {
        tmp = Zr * Zr - Zi * Zi + real;
        Zi = 2 * Zi * Zr + imag;
        Zr = tmp;
        i++;
    }
    if (i == fractol.MAX_iter)
        return COLOR_FIERY_ORANGE ;
    return(color_handler(fractol,i));
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
            color = equations(real, imag, *fractol);
            my_mlx_pixel_put(fractol->img, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
    