#include "fractol.h"
#include <stdio.h>

void    close_handler(var_t *fractol)
{
    mlx_destroy_image (fractol->mlx,fractol->img.img);
    mlx_destroy_window(fractol->mlx,fractol->win);
    exit(0);
}
int mouse_hook(int button, int x, int y, var_t *fractol) {
    if (button == 4) 
    {
        double mouseX = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx,  X);
        double mouseY = map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty, Y);
        fractol->cor.scaling *= 0.9;
        fractol->cor.sheftx += (mouseX - map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx, X)) ;
        fractol->cor.shefty += (mouseY - map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty, Y)) ;
        mandelbrot(fractol); 
    }
    else if (button == 5) 
    {
        double mouseX = map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx,  X);
        double mouseY = map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty,  Y);
        fractol->cor.scaling /= 0.9; 
        fractol->cor.sheftx -= (mouseX - map(x, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx,  X)) ;
        fractol->cor.shefty -= (mouseY - map(y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty,  Y)) ;
        mandelbrot(fractol); 
    }
    return (0);
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
	return (mandelbrot(fractol),0);
}
void    evant_init(var_t    *fractol)
{
        mlx_hook(fractol->win,2 ,1L<<0, key_hook,fractol);
        mlx_hook(fractol->win,4,1L<<2,mouse_hook,fractol);
}