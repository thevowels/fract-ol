/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:14:09 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 12:11:20 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "actions.h"

void	draw_pixelbase(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			f->z_re = f->min_r + ((double)f->x * (f->max_r - f->min_r)) / WIDTH;
			f->z_im = f->max_i + ((double)f->y * (f->min_i - f->max_i))
				/ HEIGHT;
			f->n = f->fractal(f);
			mlx_put_pixel(f->img.img, f->x, f->y, f->get_color(f->n,
					MAX_ITERATIONS));
			f->y++;
		}
		f->x++;
	}
}

void	draw_pointbase(t_fractol *f)
{
	mlx_delete_image(f->img.mlx, f->img.img);
	f->img.img = mlx_new_image(f->img.mlx, 3000, 2000);
	mlx_image_to_window(f->img.mlx, f->img.img, 0, 0);
	leaf_generator(f);
}

void	zoom(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double	x_math;
	double	y_math;
	double	new_x_range;
	double	new_y_range;

	x_math = fractol->min_r + ((double)x / WIDTH) * (fractol->max_r
			- fractol->min_r);
	y_math = fractol->min_i + (1 - (double)y / HEIGHT) * (fractol->max_i
			- fractol->min_i);
	new_x_range = (fractol->max_r - fractol->min_r) / zoom_factor;
	new_y_range = (fractol->max_i - fractol->min_i) / zoom_factor;
	fractol->min_r = x_math - ((double)x / WIDTH) * new_x_range;
	fractol->max_r = fractol->min_r + new_x_range;
	fractol->min_i = y_math - (1 - (double)y / HEIGHT) * new_y_range;
	fractol->max_i = fractol->min_i + new_y_range;
}

void	move(t_fractol *f, double distance, char direction)
{
	double	width;
	double	height;

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
