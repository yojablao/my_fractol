/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 23:19:27 by yojablao          #+#    #+#             */
/*   Updated: 2024/04/19 05:09:00 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
#define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include "src/libft.h"

#define X 1080
#define Y 1350
#define NEW_MAX_X 2
#define NEW_MAX_Y 2
#define NEW_MIN_Y -2
#define NEW_MIN_X -2

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				img_t;

typedef struct variables
{

	void	*mlx;
	void	*win;
	img_t	img;
    double  real_min;
    double  real_max;
    double  imag_min;
    double  imag_max;
}	var_t ;

void fractol_conection(var_t *fractol);



#endif
