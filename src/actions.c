/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:14:09 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 06:09:43 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_fractol *f)
{
	ft_printf("drawing ");
	mlx_delete_image(f->img.mlx, f->img.img);
	f->img.img = mlx_new_image(f->img.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(f->img.mlx, f->img.img, 0, 0);
	f->x = 0;
	f->y = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			f->z_re = f->min_r + ((double)f->x * (f->max_r - f->min_r)) / WIDTH;
			f->z_im = f->max_i + ((double)f->y * (f->min_i - f->max_i)) / HEIGHT;
			f->n = f->fractal(f);
			mlx_put_pixel(f->img.img, f->x, f->y, f->get_color(f->n,
					MAX_ITERATIONS));
			f->y++;
		}
		f->x++;
	}
}
// void	draw(t_fractol *f)
// {
// 	mlx_delete_image(f->img.mlx, f->img.img);
// 	f->img.img = mlx_new_image(f->img.mlx, WIDTH, HEIGHT);
// 	f->x = 0;
// 	f->y = 0;
// 	while (f->x < WIDTH)
// 	{
// 		f->y = 0;
// 		while (f->y < HEIGHT)
// 		{
// 			f->z_re = f->min_r + (double)f->x * (f->max_r - f->min_r) / WIDTH;
// 			f->z_im = f->max_i + (double)f->y * (f->min_i - f->max_i) / HEIGHT;
// 			f->n = f->fractal(f);
// 			ft_printf("%d , %d \n", f->x, f->y);
// 			mlx_put_pixel(f->img.img, f->x, f->y, f->get_color(f->n,
// 					MAX_ITERATIONS));
// 			f->y++;
// 		}
// 		f->x++;
// 	}
// 	ft_printf("end of draw");
// }
// static double	map(int pixel, double max_px, double min_math, double max_math)
// {
// 	double	range;

// 	range = max_math - min_math;
// 	return ((double)pixel * (range / max_px) + min_math);
// }

// void	zoom(t_fractol *f, int x, int y, double zoom_factor)
// {
// 	double	mouse_r;
// 	double	mouse_i;

// 	// 1. Where is the mouse in math coordinates?
// 	mouse_r = map(x, WIDTH, f->min_r, f->max_r);
// 	mouse_i = map(HEIGHT - y, HEIGHT, f->max_i, f->min_i);
// 	// Note: flipped for Y axis
// 	// 2. Apply the zoom factor to the ranges
// 	f->min_r = mouse_r + (f->min_r - mouse_r) * zoom_factor;
// 	f->max_r = mouse_r + (f->max_r - mouse_r) * zoom_factor;
// 	f->min_i = mouse_i + (f->min_i - mouse_i) * zoom_factor;
// 	f->max_i = mouse_i + (f->max_i - mouse_i) * zoom_factor;
// }

#include <stdio.h>
void	zoom(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double	x_math;
	double	y_math;
	double	new_x_range;
	double	new_y_range;

	x_math = fractol->min_r + ((double)x / WIDTH)
		* (fractol->max_r - fractol->min_r);
	y_math = fractol->min_i + (1 - (double)y / HEIGHT)
		* (fractol->max_i - fractol->min_i);
	new_x_range = (fractol->max_r - fractol->min_r) / zoom_factor;
	new_y_range = (fractol->max_i - fractol->min_i) / zoom_factor;
	fractol->min_r = x_math - ((double)x / WIDTH) * new_x_range;
	fractol->max_r = fractol->min_r + new_x_range;
	fractol->min_i = y_math - (1 - (double)y / HEIGHT) * new_y_range;
	fractol->max_i = fractol->min_i + new_y_range;

	printf(" I => %f %f R %f %f\n", fractol->min_i ,fractol->max_i, fractol->min_r, fractol->max_r);
}


void	move(t_fractol *f, double distance, char direction)
{
	double width;
	double height;
	
	ft_printf("Moving to %c\n", direction);
	width = f->max_r - f->min_r;
	height = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += width * distance;
		f->max_r += width * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= width * distance;
		f->max_r -= width * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += height * distance;
		f->max_i += height * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= height * distance;
		f->max_i -= height * distance;
	}
}