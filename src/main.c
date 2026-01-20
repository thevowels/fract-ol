// Written by Bruh

#include "fractol.h"
#include "actions.h"
#include "hooks.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	t_img		img;

	img.mlx = mlx_init(WIDTH,HEIGHT,"Fractol", true);
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	if(!img.img)
		return (EXIT_FAILURE);
	fractol.img = img;
	parse_args(argc, argv, &fractol);
	help_msg();
	if(fractol.is_error == -1)
		return (EXIT_FAILURE);
	init(&fractol);
	draw(&fractol);
	mlx_scroll_hook(img.mlx,&mouse_hook, &fractol);
	mlx_key_hook(img.mlx, &keyboard_hook, &fractol);
	mlx_loop(fractol.img.mlx);
	mlx_terminate(fractol.img.mlx);
	return (EXIT_SUCCESS);
}