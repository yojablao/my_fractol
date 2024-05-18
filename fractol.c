/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:07:50 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/18 16:42:38 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_ret(var_t *fractol,char *r,char *i)
{
	fractol->Cr = ft_atoi_double(r);
	fractol->Ci = ft_atoi_double(i);
}

int main(int c ,char **v)
{


	var_t	fractol;
	if(c == 2)
	{
		fractol.fractal_type = 0;
		fractol_conection(&fractol);
	}
	else if(c == 4 && ft_strncmp(v[1],"Julia",5) == 0)
	{
		fractol.fractal_type = 1;
		fractol.r = v[2];
		fractol.i = v[3];
		fractol_conection(&fractol);
	}
	else if(c == 3)
	{
		fractol.fractal_type = 2;
		fractol_conection(&fractol);
	}
	else
	{
		fractol.fractal_type = -1;
		fractol_conection(&fractol);
		exit(1);
	}

}
