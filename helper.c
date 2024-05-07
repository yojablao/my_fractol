#include "fractol.h"

void    reset(var_t *fractol)
{
    fractol->color = 1;
    fractol->MAX_iter = 40;
    fractol->cor.scaling = 1;
    fractol->cor.sheftx = 0;
    fractol->cor.shefty = 0;
}





void	my_mlx_pixel_put( t_imag img,int x, int y, int color)
{
	int	offset;

	offset = (y * img.line_length) + (x * (img.bits_per_pixel / 8));
	*(int *)(img.addr + offset) = color;
}
double map(double unscaled_num,double min,double max ,double olmin,double oldmax)
{
	return((max - min) * (unscaled_num - olmin) / (oldmax - olmin) + min);
}
// int equations(double real,double imag,int MAX_iter)
// {
// 	double Zr;
// 	double Zi;
// 	double  tmp;
// 	int i;
// 	int color;

// 	Zi = real;
// 	Zr = imag;
// 	i = 0;
//     double juliarl = 0.285, juliaim = 0.01;
// 	while(Zi*Zi + Zr*Zr <= 4 && i < MAX_iter )
// 	{
// 		tmp = Zr * Zr - Zi * Zi + real;
// 		Zi  = 2 * Zi * Zr + imag;
// 		Zr = tmp;
// 		i++;
// 	}

// 	return (i == MAX_iter ? COLOR_KHAKI/25 : i);
// }
int equations(double real,double imag,int MAX_iter)
{
	double Zr;
	double Zi;
	double  tmp;
	int i;
	int color;

	Zi = 0.0;
	Zr = 0.0;
	i = 0;

	while(Zi*Zi + Zr*Zr <= 4 && i < MAX_iter )
	{
		tmp = Zr * Zr - Zi * Zi + real;
		Zi  = 2 * Zi * Zr + imag;
		Zr = tmp;
		i++;
	}
    double smooth_value = i + 1 - log(log(sqrt(Zr * Zr + Zi * Zi))) / log(2);
	return (smooth_value );
}
     void mandelbrot(var_t *fractol) {
    int x;
    int y;
    double real;
    double imag;
    int color;

    y = 0;
    while (y < Y) {
        x = 0;
        while (x < X) {
            real = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx, 0, X);
            imag = map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty, 0, Y);
            color = equations(real, imag, fractol->MAX_iter) ;
            if(color > fractol->MAX_iter * 0.90)
                my_mlx_pixel_put(fractol->img, x, y, COLOR_LAVENDER/20);
            else
            {

                int r = (color * 7) % 25; // Vary the red component
                int g = (color * 13) % 25; // Vary the green component
                int b = (color * 19) % 25; // Vary the blue component

                color = (r << 16) + (g << 8) + b;
                my_mlx_pixel_put(fractol->img, x, y, color * fractol->color);

                }
            x++;
        }
        y++;
    }

    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
} 
// void mandelbrot(var_t *fractol) {
//     int x;
//     int y;
//     double real;
//     double imag;
//     int color    ;
//     y = 0;
//     while (y < Y) {
//         x = 0;
//         while (x < X) {
//             real = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling +fractol->cor.sheftx ,0, X)  ;
//             imag = map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling +fractol->cor.shefty ,0, Y) ;
//             color = equations(real, imag, fractol->MAX_iter);
//             color = color * fractol->color / 5;
//             int r = (color >> 16) & 0xFF;
//             int g = (color >> 8) & 0xFF;
//             r = r * 2; 
//             g = g * 2;
//             color = (r << 16) + (g << 8)  ;
//             my_mlx_pixel_put(fractol->img, x, y, color );

//             x++;
//             }
            
//                     y++;

//     }
    
//     mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
// }
void fractol_conection(var_t *fractol)
{
    fractol->mlx = mlx_init();
    if(!fractol->mlx)
        ft_putstr_fd("9lawi hada",2);
    fractol->win = mlx_new_window(fractol->mlx,X,Y,"fractol");
    if(!fractol->win)
    {
        ft_putstr_fd("rtfm",2);
        free(fractol->mlx);
        exit(1); 
    }
    fractol->img.img = mlx_new_image(fractol->mlx,X,Y);
    if(!fractol->img.img)
    {
        mlx_destroy_window(fractol->mlx,fractol->win);
        ft_putstr_fd("rtfm",2);
        free(fractol->mlx);
        exit(1);
    }
    fractol->img.addr = mlx_get_data_addr(fractol->img.img,
                                                &fractol->img.bits_per_pixel,
                                                &fractol->img.line_length,
                                                &fractol->img.endian);
    reset(fractol);     
    mandelbrot(fractol);                                    
    evant_init(fractol);
    mlx_loop(fractol->mlx);
}
    