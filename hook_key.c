/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:14:31 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/23 03:16:09 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

void	handle_iterations(int keysym, var_t *fractol)
{
	if (keysym == 34)
		fractol->MAX_iter += 10;
	else if (keysym == 35)
		fractol->MAX_iter -= 10;
}

void	handle_movement_or_zoom(int keysym, var_t *fractol)
{
	if (keysym == 124)
		fractol->cor.sheftx += 0.09 * fractol->cor.scaling;
	else if (keysym == 69)
		fractol->cor.scaling *= 2;
	else if (keysym == 78)
		fractol->cor.scaling /= 2;
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
	if (keysym == 8)
	{
		if(fractol->color >= 2)
			fractol->color = -1;
		else
			fractol->color += 1;
	}
	if(keysym ==)
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