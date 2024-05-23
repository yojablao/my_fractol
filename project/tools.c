/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:46:58 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/23 02:53:22 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
void    reset(var_t *fractol)
{
    fractol->color = -1;
    fractol->MAX_iter = 100;
    fractol->cor.scaling = 1;
    fractol->cor.sheftx = 0;
    fractol->cor.shefty = 0;
    if(fractol->fractal_type == 2)
            fractol->sin = -1;
    else
        fractol->sin = 1;
    if(fractol->fractal_type == 1)
    {
        printf("%s\n,%s\n",fractol->r,fractol->i);
	    fractol->Cr = ft_atoi_double(fractol->r);
	    fractol->Ci = ft_atoi_double(fractol->i);
        if(!fractol->Ci && !fractol->Cr)
        {
            fractol->Ci = -0.3842;
            fractol->Cr = -0.70176;
        }
    }
}

void	my_mlx_pixel_put( t_imag img,int x, int y, int color)
{
	int	offset;

	offset = (y * img.line_length) + (x * (img.bits_per_pixel / 8));
	*(unsigned int *)(img.addr + offset) = color;
}
double map(double unscaled_num,double min,double max ,double oldmax)
{
	return((max - min) * (unscaled_num - 0) / (oldmax - 0) + min);
}
int signe(const char *str, int *c)
{
    int sign;
    int i;

    i = 0;
    sign = 1;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    *c = i;
    return (sign);
}

double ft_atoi_double(const char *str)
{
    int i;
    int j;
    int sign;
    double result;
    double fractional_part;

    sign = signe(str, &i);
    result = 0.00;
    while (ft_isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.' || str[i] == ',')
    {
        fractional_part = 0.00;
        j = i + 1;
        while (ft_isdigit(str[++i]))
            fractional_part = fractional_part * 10 + (str[i] - '0');
        j = i - j;
        while (j--)
            fractional_part /= 10;
        result += fractional_part;
    }
    return (result * sign);
}