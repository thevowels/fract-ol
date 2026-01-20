/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 01:54:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 03:06:46 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "fractol.h"
#include "hooks.h"


// int	main(void)
// {
// 	// t_fractol	fractol;
// 	t_img		img;

// 	// img.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
// 	// img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
// 	// if (!img.img)
// 	// 	return (EXIT_FAILURE);
// 	// mlx_image_to_window(img.mlx, img.img, 0,0);
// 	// int x;
// 	// int y;
// 	// x  = 300;
// 	// y = 300;
// 	// while(x < 800)
// 	// {
// 	// 	y = 300;
// 	// 	while(y < 800)
// 	// 	{
// 	// 		mlx_put_pixel(img.img, x,y, 0xFF0000FF);
// 	// 		y++;
// 	// 	}
// 	// 	x++;
// 	// }
// 	// fractol.img = img;
// 	// parse_args(argc, argv, &fractol);
// 	// help_msg();
// 	// if (fractol.is_error == -1)
// 	// 	return (EXIT_FAILURE);
// 	// init(&fractol);
// 	// draw(&fractol);
// 	// mlx_scroll_hook(img.mlx, &mouse_hook, &fractol);
// 	// mlx_key_hook(img.mlx, &keyboard_hook, &fractol);
// 	mlx_loop(img.mlx);
// 	mlx_terminate(img.mlx);
// 	return (EXIT_SUCCESS);
// }



int	main(int argc, char **argv)
{
	t_fractol	fractol;
	t_img		img;

	img.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	if (!img.img)
		return (EXIT_FAILURE);
	fractol.img = img;
	parse_args(argc, argv, &fractol);
	help_msg();
	if (fractol.is_error == -1)
		return (EXIT_FAILURE);
	init(&fractol);
	draw(&fractol);
	mlx_scroll_hook(img.mlx, &mouse_hook, &fractol);
	mlx_key_hook(img.mlx, &keyboard_hook, &fractol);
	// keyboard_hook(&fractol);
	// mlx_loop_hook(img.mlx, keyboard_hook, &fractol);
	mlx_loop(fractol.img.mlx);
	mlx_terminate(fractol.img.mlx);
	return (EXIT_SUCCESS);
}

// #include "../lib/MLX42/include/MLX42/MLX42.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #define WIDTH 256
// #define HEIGHT 256

// // Exit the program as failure.
// static void	ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// // Print the window width and height.
// static void	ft_hook(void *param)
// {
// 	const mlx_t	*mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// int32_t	main(void)
// {

// 	int x;
// 	int y;

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		ft_error();

// 	/* Do stuff */

// 	// Create and display the image.
// 	mlx_image_t* img = mlx_new_image(mlx, 1024, 1024);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_error();

// 	// Even after the image is being displayed, we can still modify the buffer.
// 	x = 100;
// 	while(x < 500)
// 	{
// 		y = 100;
// 		while(y < 200)
// 		{
// 			mlx_put_pixel(img, x,y, 0xFF0000FF);
// 			y++;
// 		}
// 		x++;
// 	}

// 	// Register a hook and pass mlx as an optional param.
// 	// NOTE: Do this before calling mlx_loop!
// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
