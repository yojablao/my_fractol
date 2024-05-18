#include "fractol.h"

void    reset(var_t *fractol)
{
    fractol->color = 1;
    fractol->MAX_iter = 50;
    fractol->cor.scaling = 1;
    fractol->cor.sheftx = 0;
    fractol->cor.shefty = 0;
    if(fractol->fractal_type == 2)
            fractol->sin = -1;
    else
        fractol->sin = 1;
    if(fractol->fractal_type == 1)
    {
	    fractol->Cr = ft_atoi_double(fractol->r);
	    fractol->Ci = ft_atoi_double(fractol->i);
    }
}
void ft_color(int iteration, int *red, int *green, int *blue) {
    *red = (iteration * 10) % 256;
    *green = (iteration * 10) % 256;
    *blue = (iteration * 2) % 256;
}

void	my_mlx_pixel_put( t_imag img,int x, int y, int color)
{
	int	offset;

	offset = (y * img.line_length) + (x * (img.bits_per_pixel / 8));
	*(unsigned int *)(img.addr + offset) = color;
}
double map(double unscaled_num,double min,double max ,double oldmax)
{
	return((max - min) * (unscaled_num - 0) / (oldmax - 0) + min);
}
static int signe(const char *str, int *c)
{
    int sign;
    int i;

    i = 0;
    sign = 1;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    *c = i;
    return (sign);
}

double ft_atoi_double(const char *str)
{
    int i;
    int j;
    int sign;
    double result;
    double fractional_part;

    sign = signe(str, &i);
    result = 0.0;
    while (ft_isdigit(str[i++]))
        result = result * 10 + (str[i] - '0');
    if (str[i] == '.' || str[i] == ',')
    {
        fractional_part = 0.0;
        j = 0;
        while (ft_isdigit(str[++i]))
        {
            fractional_part = fractional_part * 10 + (str[i] - '0');
            j++;
        }
        while (j--)
            fractional_part /= 10;
        result += fractional_part;
    }
    return (result * sign);
}
