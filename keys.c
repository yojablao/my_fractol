/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:07:55 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/18 18:37:40 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void    close_handler(var_t *fractol)
{
    mlx_destroy_image (fractol->mlx,fractol->img.img);
    mlx_destroy_window(fractol->mlx,fractol->win);
    exit(0);
}


int	key_hook(int keysym, void *param)
{
    var_t *fractol;
    fractol =  (var_t *)param;
    if (keysym == 8)
        fractol->color += 60;
    else if(keysym == 34)
        fractol->MAX_iter+= 10;
    else if(keysym == 35)
        fractol->MAX_iter-= 10;
    else if(keysym == 69)
        fractol->cor.scaling *= 2;
    else if(keysym == 78)
        fractol->cor.scaling /= 2;
    else if(keysym == 124)
            fractol->cor.sheftx +=  0.09 * fractol->cor.scaling;
    else if(keysym == 123)
            fractol->cor.sheftx -= 0.09 * fractol->cor.scaling; 
    else if(keysym == 126)
            fractol->cor.shefty += 0.09 * fractol->cor.scaling;
    else if(keysym == 125)
            fractol->cor.shefty -= 0.09 * fractol->cor.scaling;
    else if(keysym == 15)
        reset(fractol);
    if(keysym == 53)
        close_handler(fractol);
    if(fractol->fractal_type == 0)
        mandelbrot(fractol); 
    else if(fractol->fractal_type == 2)
        draw_burning_ship(fractol);
    else
        julia(fractol,fractol->Cr,fractol->Ci);
	return (0);
}
int mouse_hook(int button, int x, int y, var_t *fractol) 
{

    if (button == 4) 
    {
        double mouseX = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx,  X);
        double mouseY = map(y, (fractol->sin * 2) * fractol->cor.scaling  + fractol->cor.shefty, (fractol->sin * -2) * fractol->cor.scaling + fractol->cor.shefty, Y);
        fractol->cor.scaling *= 0.9;
        fractol->cor.sheftx += (mouseX - map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx, X)) ;
        fractol->cor.shefty += (mouseY - map(y, (fractol->sin  * 2) * fractol->cor.scaling  + fractol->cor.shefty, (fractol->sin  * -2) * fractol->cor.scaling + fractol->cor.shefty , Y)) ;

    }
    else if (button == 5) 
    {
        double mouseX = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx,  X);
        double mouseY = map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty,  Y);
        fractol->cor.scaling /= 0.9; 
        fractol->cor.sheftx -= (mouseX - map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx,  X)) ;
        fractol->cor.shefty -= (mouseY - map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty,  Y)) ;
    }
    else
    {
        if(fractol->cor.scaling == 1)
        {
            fractol->Cr =  map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx,  X);
            fractol->Ci =  map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty, Y);
        }
    }
    if(fractol->fractal_type == 0)
        mandelbrot(fractol); 
    else if(fractol->fractal_type == 1)
        julia(fractol,fractol->Cr,fractol->Ci);
    else if(fractol->fractal_type == 2)
        draw_burning_ship(fractol);
        
    return (0);
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
    reset(fractol);
    if (fractol->fractal_type == 0)
        mandelbrot(fractol);
    else if (fractol->fractal_type == 1)
        julia(fractol, fractol->Cr, fractol->Ci);
    else if(fractol->fractal_type == 2)
        draw_burning_ship(fractol);
    evant_init(fractol);
    mlx_loop(fractol->mlx);
}
