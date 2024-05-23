/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:14:41 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/21 20:21:47 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

void	zoom_in(var_t *fractol, int x, int y)
{
	double	mousex;
	double	mousey;

	mousex = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx,
			2 * fractol->cor.scaling + fractol->cor.sheftx, X);
	mousey = map(y,
			(fractol->sin * 2) * fractol->cor.scaling + fractol->cor.shefty,
			(fractol->sin * -2) * fractol->cor.scaling + fractol->cor.shefty,
			Y);
	fractol->cor.scaling *= 0.9;
	fractol->cor.sheftx += (mousex - map(x,
				-2 * fractol->cor.scaling + fractol->cor.sheftx,
				2 * fractol->cor.scaling + fractol->cor.sheftx, X));
	fractol->cor.shefty += (mousey - map(y,
				fractol->sin * 2 * fractol->cor.scaling + fractol->cor.shefty,
				fractol->sin * -2 * fractol->cor.scaling + fractol->cor.shefty,
				Y));
}

void	zoom_out(var_t *fractol, int x, int y)
{
	double	mousex;
	double	mousey;

	mousex = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx,
			2 * fractol->cor.scaling + fractol->cor.sheftx, X);
	mousey = map(y,
			(fractol->sin * 2) * fractol->cor.scaling + fractol->cor.shefty,
			(fractol->sin * -2) * fractol->cor.scaling + fractol->cor.shefty,
			Y);
	fractol->cor.scaling /= 0.9;
	fractol->cor.sheftx -= (mousex - map(x,
				-2 * fractol->cor.scaling + fractol->cor.sheftx,
				2 * fractol->cor.scaling + fractol->cor.sheftx, X));
	fractol->cor.shefty -= (mousey - map(y,
				fractol->sin * 2 * fractol->cor.scaling + fractol->cor.shefty,
				fractol->sin * -2 * fractol->cor.scaling + fractol->cor.shefty,
				Y));
}

void	handle_click(var_t *fractol, int x, int y)
{
	if (fractol->cor.scaling == 1)
	{
		fractol->Cr = map(x,
				-2 * fractol->cor.scaling + fractol->cor.sheftx,
				2 * fractol->cor.scaling + fractol->cor.sheftx, X);
		fractol->Ci = map(y,
				2 * fractol->cor.scaling + fractol->cor.shefty,
				-2 * fractol->cor.scaling + fractol->cor.shefty, Y);
	}
}

int	mouse_hook(int button, int x, int y, var_t *fractol)
{
	if (button == 4)
		zoom_in(fractol, x, y);
	else if (button == 5)
		zoom_out(fractol, x, y);
	else
		handle_click(fractol, x, y);
	if (fractol->fractal_type == 0)
		mandelbrot(fractol);
	else if (fractol->fractal_type == 1)
		julia(fractol);
	else if (fractol->fractal_type == 2)
		draw_burning_ship(fractol);
	return (0);
}
