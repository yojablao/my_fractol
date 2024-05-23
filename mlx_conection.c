/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_conection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:07:55 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/20 21:00:00 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void    close_handler(var_t *fractol)
{
    mlx_destroy_image(fractol->mlx,fractol->img.img);
    mlx_destroy_window(fractol->mlx,fractol->win);
    exit(0);
}

void    evant_init(var_t    *fractol)
{
        mlx_hook(fractol->win,2 ,1L<<0, key_hook,fractol);
        mlx_hook(fractol->win,4,1L<<2,mouse_hook,fractol);
}
void fractol_conection(var_t *fractol)
{
    fractol->mlx = mlx_init();
    if (!fractol->mlx)
        exit(-1);
    fractol->win = mlx_new_window(fractol->mlx, X, Y, "fractol");
    if (!fractol->win)
       return(free(fractol->mlx), exit(1));
    fractol->img.img = mlx_new_image(fractol->mlx, X, Y);
    if (!fractol->img.img)
        return( mlx_destroy_window(fractol->mlx, fractol->win),free(fractol->mlx), exit(2));
    fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel, &fractol->img.line_length , &fractol->img.endian);
    
}
