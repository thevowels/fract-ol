/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:14:09 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 09:47:04 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_fractol *f)
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
// void	draw(t_fractol *f)
// {
// 	mlx_delete_image(f->img.mlx, f->img.img);
// 	f->img.img = mlx_new_image(f->img.mlx, WIDTH, HEIGHT);
// 	mlx_image_to_window(f->img.mlx, f->img.img, 0, 0);
// 	int      i;
//     double   next_x;
//     double   next_y;
//     double   r;
//     int      px;
//     int      py;

//     f->z_re = 0;
//     f->z_im = 0;
//     i = 0;
//     // The fern needs a lot of points to look solid
//     while (i < 100000) 
//     {
//         r = (double)rand() / RAND_MAX;
//         if (r < 0.01)
//         {
//             next_x = 0;
//             next_y = 0.16 * f->z_im;
//         }
//         else if (r < 0.86)
//         {
//             next_x = 0.85 * f->z_re + 0.04 * f->z_im;
//             next_y = -0.04 * f->z_re + 0.85 * f->z_im + 1.6;
//         }
//         else if (r < 0.93)
//         {
//             next_x = 0.20 * f->z_re - 0.26 * f->z_im;
//             next_y = 0.23 * f->z_re + 0.22 * f->z_im + 1.6;
//         }
//         else
//         {
//             next_x = -0.15 * f->z_re + 0.28 * f->z_im;
//             next_y = 0.26 * f->z_re + 0.24 * f->z_im + 0.44;
//         }
//         f->z_re = next_x;
//         f->z_im = next_y;

//         // Map the math coordinates to your screen WIDTH/HEIGHT
//         px = (int)((f->z_re - f->min_r) / (f->max_r - f->min_r) * WIDTH);
//         py = (int)((f->max_i - f->z_im) / (f->max_i - f->min_i) * HEIGHT);

//         if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT)
//             mlx_put_pixel(f->img.img, px, py, 0x228B22FF); // Forest Green
//         i++;
// 	}
// }

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
