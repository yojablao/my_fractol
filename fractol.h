/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 23:19:27 by yojablao          #+#    #+#             */
/*   Updated: 2024/05/13 19:31:01 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
#define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include "src/libft.h"

#define X 1000
#define Y 1000
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
#define COLOR_BLUE  0x0000FF
#define COLOR_YELLOW 0xFFFF00
#define COLOR_CYAN  0x00FFFF
#define COLOR_MAGENTA 0xFF00FF
#define COLOR_GRAY 0x808080
#define COLOR_BLACK 0x000000
#define COLOR_LIGHT_BLUE 0xADD8E6
#define COLOR_BLACK      0x000000
#define COLOR_DARK_PURPLE 0x4B0082
#define COLOR_DEEP_RED   0x8B0000
#define COLOR_FIERY_ORANGE 0xFF4500
#define COLOR_ELECTRIC_BLUE 0x7DF9FF
#define COLOR_LIME_GREEN 0x32CD32
#define COLOR_GOLD 0xFFD700



#define COLOR_HOT_PINK 0xFF69B4
#define COLOR_INDIGO 0x4B0082
#define COLOR_JADE 0x00A86B
#define COLOR_KHAKI 0xC3B091
#define COLOR_LAVENDER 0xE6E6FA
#define COLOR_MAROON 0x800000
#define COLOR_NAVY_BLUE 0x000080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imag;
typedef struct hook_s
{
		double 	scaling;
		double	sheftx;
		double	shefty;
		
}hook_t;
typedef struct color_s
{
		int	color;
		int red;
		int green;
		int blue;
		int color_shift;
		
}t_color;


typedef struct variables
{

	void	*mlx;
	void	*win;
	t_imag	img;
	int		color;
	int		MAX_iter;
	hook_t	cor;
}	var_t ;
// typedef	struct map
// {
// 	double 
// }

void fractol_conection(var_t *fractol);
void    evant_init(var_t    *fractol);
int	key_hook(int keysym, void *param);
void mandelbrot(var_t *fractol);
double map(double unscaled_num,double min,double max ,double oldmax);
void    reset(var_t *fractol);
void    evant_init(var_t    *fractol);




#endif
