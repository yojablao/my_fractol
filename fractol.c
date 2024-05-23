/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:07:50 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/23 02:11:00 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	check_fractol(char **v, int c, var_t *fractol)
{
	if (c == 2 && ft_strncmp(v[1], "Mandelbrot", sizeof(v[1])) == 0)
		return (0);
	if (c == 4 && ft_strncmp(v[1], "Julia", sizeof(v[1])) == 0)
	{
		fractol->r = v[2];
		fractol->i = v[3];
		return (1);
	}
	if (c == 2 && ft_strncmp(v[1], "Burning Ship", sizeof(v[1])) == 0)
		return (2);
	else
		exit(-1);
}


int	main(int c, char **v)
{
	var_t	fractol;

	fractol.names = v[1];
	fractol.fractal_type = check_fractol(v, c, &fractol);
	fractol_conection(&fractol);
	reset(&fractol);
	if (fractol.fractal_type == 0)
		mandelbrot(&fractol);
	else if (fractol.fractal_type == 1)
		julia(&fractol);
	else if (fractol.fractal_type == 2)
		draw_burning_ship(&fractol);
	else
		exit(0);
	evant_init(&fractol);
	mlx_loop(fractol.mlx);
}
