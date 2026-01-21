/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 01:54:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 12:34:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "fractol.h"
#include "hooks.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	t_img		img;

	img.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	if (!img.img)
		return (EXIT_FAILURE);
	fractol.img = img;
	init(&fractol);
	parse_args(argc, argv, &fractol);
	help_msg();
	if (fractol.is_error == -1)
		return (EXIT_FAILURE);
	fractol.draw(&fractol);
	mlx_scroll_hook(img.mlx, &mouse_hook, &fractol);
	mlx_key_hook(img.mlx, &keyboard_hook, &fractol);
	mlx_loop_hook(img.mlx, &frame_hook, &fractol);
	mlx_resize_hook(img.mlx, &resize_hook, &fractol);
	mlx_loop(fractol.img.mlx);
	mlx_terminate(fractol.img.mlx);
	return (EXIT_SUCCESS);
}
