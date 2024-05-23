/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 02:08:44 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/23 03:41:42 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_color(var_t fractol, int iter)
{
	double	t;
	
	t = (double)iter / (double)fractol.MAX_iter;
	fractol.colors.red = (int)(9 * (1 - t) * t * t * t * 255);
	fractol.colors.green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	fractol.colors.blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((fractol.colors.red << 16) | (fractol.colors.green << 8)
		|fractol.colors.blue);
}
int	ft_color1(var_t fractol, int iter)
{
	double	t;
	
	t = (double)iter / (double)fractol.MAX_iter;
	fractol.colors.red = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	fractol.colors.green = (int)(9 * (1 - t) * t * 255);
	fractol.colors.blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return ((fractol.colors.green << 16) | (fractol.colors.blue << 8)
		|fractol.colors.red);
}
int	ft_color2(var_t fractol, int iter)
{
	double	t;
	
	t = (double)iter / (double)fractol.MAX_iter;
	fractol.colors.red = (int)(9 * (1 - t) * t * t * t * 255);
	fractol.colors.green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	fractol.colors.blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return ((fractol.colors.green << 16) | (fractol.colors.blue << 8)
		|fractol.colors.red);
}
int	ft_color3(var_t fractol, int iter)
{
	double	t;
	
	t = (double)iter / (double)fractol.MAX_iter;

	fractol.colors.red = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * t * 255);
	fractol.colors.green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	fractol.colors.blue = (int)(9 * (1 - t) * t * 255);
    return ((fractol.colors.blue << 16) | (fractol.colors.green << 8)
		|fractol.colors.red);
}
int color_handler(var_t fractol,int iter)
{
    // if(iter == fractol.MAX_iter)
    //     return (ft_color_max_iter(fractol));
    if (fractol.color == 1)
        return(ft_color1(fractol,iter));
        
    if (fractol.color == 0)
        return (ft_color2(fractol,iter));
    else if (fractol.color == 2)
        return (ft_color3(fractol,iter));
    return (ft_color(fractol,iter));
}
