#include "fractol.h"


void    close_handler(var_t *fractol)
{
    // mlx_clear_window(fractol->mlx,fractol->win);
    // perror("0");
    mlx_destroy_image (fractol->mlx,fractol->img.img);
    // perror("1");
    mlx_destroy_window(fractol->mlx,fractol->win);
    // perror("2");
    // free(fractol->mlx);
    exit(0);
}

int mouse_hook(int button, int x, int y, var_t *fractol) {
    // printf("Mouse click at x=%d, y=%d\n", x, y);

    // Calculate the center of the current view
    double center_real = map(x, 0, X, -2 * fractol->cor.scaling + fractol->cor.sheftx, 2 * fractol->cor.scaling + fractol->cor.sheftx);
    double center_imag = map(y, 0, Y, 2 * fractol->cor.scaling + fractol->cor.shefty, -2 * fractol->cor.scaling + fractol->cor.shefty);

    if (button == 5) {
        // Zoom in (scroll up)
        double prev_scaling = fractol->cor.scaling;
        fractol->cor.scaling *= 0.9;

        // Adjust the center based on the new scaling
        fractol->cor.sheftx += center_real - x  * 0.2;
        fractol->cor.shefty += center_imag - y * 0.2;

        // Compensate for the shift due to scaling change
        // fractol->cor.sheftx += (prev_scaling - fractol->cor.scaling) * x;
        // fractol->cor.shefty += (prev_scaling - fractol->cor.scaling) * y;
    } else if (button == 4) {
        // Zoom out (scroll down)
        double prev_scaling = fractol->cor.scaling;
        fractol->cor.scaling /= 0.9;

        // Adjust the center based on the new scaling
        fractol->cor.sheftx = center_real - (x * fractol->cor.scaling);
        fractol->cor.shefty = center_imag - (y * fractol->cor.scaling);

        // Compensate for the shift due to scaling change
        fractol->cor.sheftx += (prev_scaling - fractol->cor.scaling) * x;
        fractol->cor.shefty += (prev_scaling - fractol->cor.scaling) * y;
    }

    // Recalculate the fractal
    mandelbrot(fractol);

    return 0;
}
// int mouse_hook(int button, int x, int y, var_t *fractol) {
//     printf("x=%d, y=%d\n", x, y);
//     if (button == 5)
//     {

//         fractol->cor.scaling *= 0.9;
//     }
//     else if (button == 4) 
//     {
//         fractol->cor.scaling /= 0.9;
//     }


//     mandelbrot(fractol);

//     return 0;
// }
int	key_hook(int keysym, void *param)
{
    var_t   *fractol;

    fractol = (var_t *)param;
    // printf("%d\n",keysym)  ;
    if (keysym == 8)
        fractol->color += 1;

    else if(keysym == 34)
        fractol->MAX_iter+= 10;

    else if(keysym == 35)
        fractol->MAX_iter-= 10;

    else if(keysym == 69)
        fractol->cor.scaling *= 0.9;

    else if(keysym == 78)
        fractol->cor.scaling /= 0.9;

    else if(keysym == 124)
            fractol->cor.sheftx +=  0.05 * fractol->cor.scaling;

    else if(keysym == 123)
            fractol->cor.sheftx -= 0.05* fractol->cor.scaling; 

    else if(keysym == 126)
            fractol->cor.shefty += 0.05* fractol->cor.scaling;

    else if(keysym == 125)
            fractol->cor.shefty -= 0.05* fractol->cor.scaling;

    else if(keysym == 15)
        reset(fractol);
    if(keysym == 53)
        close_handler(fractol);
    mandelbrot(fractol);
	return 0;

}
void    evant_init(var_t    *fractol)
{
        mlx_hook(fractol->win,2 ,1L<<0, key_hook,fractol);
        mlx_hook(fractol->win,4,1L<<2,mouse_hook,fractol);
}