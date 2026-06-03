/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 03:07:59 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/06/04 03:18:44 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "fractol.h"

void	put_color_block(t_fractol *f, int block_size)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	y = 0;
	color = f->get_color(f->n, MAX_ITERATIONS);
	while (x < block_size)
	{
		y = 0;
		while (y < block_size && f->x + x < f->width && f->y + y < f->height)
		{
			mlx_put_pixel(f->img.img, f->x + x, f->y + y, color);
			y++;
		}
		x++;
	}
}

void	actual_draw_pixelbase(t_fractol *f, int block_size)
{
	f->x = 0;
	f->y = 0;
	while (f->x < f->width - block_size)
	{
		f->y = 0;
		while (f->y < f->height - block_size)
		{
			f->z_re = f->min_r + ((double)f->x * (f->max_r - f->min_r))
				/ f->width;
			f->z_im = f->max_i + ((double)f->y * (f->min_i - f->max_i))
				/ f->height;
			f->n = f->fractal(f);
			put_color_block(f, block_size);
			f->y += block_size;
		}
		f->x += block_size;
	}
}

void	render_hook(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (fractol->render != 0)
	{
		actual_draw_pixelbase(fractol, pow(2, fractol->render));
		fractol->render -= 1;
	}
}
