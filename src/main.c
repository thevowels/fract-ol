// Written by Bruh

#include <stdio.h>

#include "fractol.h"
#include "colors.h"
#include "fractals.h"
#include "hooks.h"
#include "image.h"
#include "init.h"
void	parse_args(int argc, char **argv, t_fractol *fractol);

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
void help_msg(void)
{
	printf("blah blah\n");
}
int	main(int argc, char **argv)
{
	t_fractol	fractol;
	t_img		img;

	img.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	if (!img.img)
		return (1);
	fractol.img = img;
	parse_args(argc, argv, &fractol);
	if (fractol.error == -1)
	{
		help_msg();
		return (1);
	}
	help_msg();
	init(&fractol);
	draw_fractal(&fractol);
	mlx_scroll_hook(img.mlx, &handle_mouse, &fractol);
	mlx_key_hook(img.mlx, &handel_keyboard, &fractol);
	mlx_loop(fractol.img.mlx);
	mlx_terminate(fractol.img.mlx);
	return (EXIT_SUCCESS);
}
