/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:06:47 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 12:11:37 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	while (i < 1000000)
	{
		leaf_choice(&leaf, f);
		f->z_re = leaf.next_x;
		f->z_im = leaf.next_y;
		leaf.px = (int)((f->z_re - f->min_r) / (f->max_r - f->min_r) * WIDTH);
		leaf.py = (int)((f->max_i - f->z_im) / (f->max_i - f->min_i) * HEIGHT);
		if (leaf.px >= 0 && leaf.px < WIDTH && leaf.py >= 0 && leaf.py < HEIGHT)
			mlx_put_pixel(f->img.img, leaf.px, leaf.py, 0x228B22FF);
		i++;
	}
}
