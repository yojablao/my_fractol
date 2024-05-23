/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:45:46 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/23 10:50:00 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int burning_ship(double real, double imag, var_t fractol) 
{
    double Zr = 0.0;
    double Zi = 0.0;
    double tmp;
    int i;

    i = 0;
    while (Zi * Zi + Zr * Zr <= 4 && i < fractol.MAX_iter) {
        tmp = Zr * Zr - Zi * Zi + real;
        Zi = fabs(2 * Zi * Zr) + imag;
        Zr = fabs(tmp);
        i++;
    }
    if (i == fractol.MAX_iter)
        return COLOR_GOLD ;
    return(color_handler(fractol,i));
    
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
            color = burning_ship(real, imag, *fractol);
            my_mlx_pixel_put(fractol->img, x, y, color + fractol->color);
            x++;
        }
        y++;
    }

    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
