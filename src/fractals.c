/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:35:17 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 12:48:29 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	julia(t_fractol *f)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((f->z_im * f->z_im + f->z_re * f->z_re) > 4.0)
			break ;
		tmp = 2 * f->z_re * f->z_im + f->c_im;
		f->z_re = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re;
		f->z_im = tmp;
		n++;
	}
	return (n);
}

int	mandelbrot(t_fractol *f)
{
	int		n;
	double	tmp;

	n = 0;
	f->z_re = 0;
	f->z_im = 0;
	f->c_re = f->min_r + (double)f->x / f->width * (f->max_r - f->min_r);
	f->c_im = f->max_i - (double)f->y / f->height * (f->max_i - f->min_i);
	while (n < MAX_ITERATIONS)
	{
		if ((f->z_im * f->z_im + f->z_re * f->z_re) > 4.0)
			break ;
		tmp = 2 * f->z_re * f->z_im + f->c_im;
		f->z_re = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re;
		f->z_im = tmp;
		n++;
	}
	return (n);
}

void	leaf_choice(t_leaf *leaf, t_fractol *f)
{
	double	r;

	r = (double)rand() / RAND_MAX;
	if (r < 0.01)
	{
		leaf->next_x = 0;
		leaf->next_y = 0.16 * f->z_im;
	}
	else if (r < 0.86)
	{
		leaf->next_x = 0.85 * f->z_re + 0.04 * f->z_im;
		leaf->next_y = -0.04 * f->z_re + 0.85 * f->z_im + 1.6;
	}
	else if (r < 0.93)
	{
		leaf->next_x = 0.20 * f->z_re - 0.26 * f->z_im;
		leaf->next_y = 0.23 * f->z_re + 0.22 * f->z_im + 1.6;
	}
	else
	{
		leaf->next_x = -0.15 * f->z_re + 0.28 * f->z_im;
		leaf->next_y = 0.26 * f->z_re + 0.24 * f->z_im + 0.44;
	}
}

void	leaf_generator(t_fractol *f)
{
	long	i;
	t_leaf	leaf;

	i = 0;
	f->width = f->img.mlx->width;
	f->height = f->img.mlx->height;
	while (i < 1000000)
	{
		leaf_choice(&leaf, f);
		f->z_re = leaf.next_x;
		f->z_im = leaf.next_y;
		leaf.px = (int)((f->z_re - f->min_r) / (f->max_r - f->min_r)
				* f->width);
		leaf.py = (int)((f->max_i - f->z_im) / (f->max_i - f->min_i)
				* f->height);
		if (leaf.px >= 0 && leaf.px < f->width && leaf.py >= 0
			&& leaf.py < f->height)
			mlx_put_pixel(f->img.img, leaf.px, leaf.py, 0x228B22FF);
		i++;
	}
}
