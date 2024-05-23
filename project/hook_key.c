/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:14:31 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/23 10:22:29 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

void	handle_iterations(int keysym, var_t *fractol)
{
	if (keysym == 34)
		fractol->MAX_iter += 50;
	else if (keysym == 35)
		fractol->MAX_iter -= 50;
}
#include <libc.h>
void	handle_movement_or_zoom(int keysym, var_t *fractol)
{
	if(keysym == 49)
	{
		fractol->cor.scaling = 1;
    	fractol->cor.sheftx = 0;
    	fractol->cor.shefty = 0;
	}
	else if (keysym == 124)
		fractol->cor.sheftx += 0.09 * fractol->cor.scaling;
	else if (keysym == 69)
		fractol->cor.scaling /= 2;
	else if (keysym == 78)
		fractol->cor.scaling *= 2;
	else if (keysym == 123)
		fractol->cor.sheftx -= 0.09 * fractol->cor.scaling;
	else if (keysym == 126)
		fractol->cor.shefty += 0.09 * fractol->cor.scaling;
	else if (keysym == 125)
		fractol->cor.shefty -= 0.09 * fractol->cor.scaling;
}

void	handle_reset_or_exit(int keysym, var_t *fractol)
{
	if (keysym == 15)
		reset(fractol);
	else if (keysym == 53)
		close_handler(fractol);
}

int	key_hook(int keysym, void *param)
{
	var_t	*fractol;

	fractol = (var_t *)param;
	if(keysym == 1)
		handle_save_bmp(fractol);
	if (keysym == 8)
	{
		if(fractol->color >= 2)
			fractol->color = -1;
		else
			fractol->color += 1;
	}
	handle_iterations(keysym, fractol);
	handle_movement_or_zoom(keysym, fractol);
	handle_reset_or_exit(keysym, fractol);
	if (fractol->fractal_type == 0)
		mandelbrot(fractol);
	else if (fractol->fractal_type == 2)
		draw_burning_ship(fractol);
	else
		julia(fractol);
	return (0);
}
