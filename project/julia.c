/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:46:33 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/23 06:02:07 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int julia_equations(double Zr, double Zi,var_t fractol)
{
    double tmp;
    int i;

    i = 0;
    while (Zi * Zi + Zr * Zr <= 4 && i < fractol.MAX_iter)
    {
        tmp = Zr * Zr - Zi * Zi + fractol.Cr;
        Zi = 2 * Zi * Zr + fractol.Ci;
        Zr = tmp;
        i++;
    }
    if (i == fractol.MAX_iter && fractol.color == -1)
        return COLOR_GOLD ;
    return(color_handler(fractol,i));
}
void julia(var_t *fractol)
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
            color = julia_equations(Zr, Zi, *fractol);
            my_mlx_pixel_put(fractol->img, x, y, color + fractol->color);
            x++;
        }
        y++;
    }

    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}



