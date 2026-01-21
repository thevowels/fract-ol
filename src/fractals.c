/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:35:17 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 09:53:38 by aphyo-ht         ###   ########.fr       */
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
	f->c_re = f->min_r + (double)f->x / WIDTH * (f->max_r - f->min_r);
	f->c_im = f->max_i - (double)f->y / HEIGHT * (f->max_i - f->min_i);
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
