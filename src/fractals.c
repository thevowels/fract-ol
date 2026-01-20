/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:35:17 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 06:06:18 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

/**
 * julia - Calculates the Julia set for a given complex number z
 * 
 * The Julia set is defined by the iterative formula: z(n+1) = z(n)^2 + c
 * where z is a complex number and c is a constant complex number.
 * 
 * For each point z in the complex plane:
 * - We iterate the formula z = z^2 + c
 * - If |z| > 2 (or |z|^2 > 4), the point escapes to infinity
 * - The number of iterations before escape determines the color
 * - Points that don't escape within MAX_ITERATIONS are considered part of the set
 * 
 * @param f: Pointer to fractol structure containing:
 *           - z_re, z_im: Real and imaginary parts of current z value
 *           - c_re, c_im: Real and imaginary parts of constant c
 * 
 * @return: Number of iterations before escape (or MAX_ITERATIONS if no escape)
 */
#include <stdio.h>
int julia(t_fractol *f)
{
	int		n;
	double	tmp;

	n = 0;
	while(n < MAX_ITERATIONS)
	{
		if((f->z_im * f->z_im + f->z_re * f->z_re) > 4.0)
			break;
		tmp = 2 * f->z_re * f->z_im + f->c_im;
		f->z_re = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re;
		f->z_im = tmp;
		n++;
	}
	return (n);
}
// int julia(t_fractol *f)
// {
// 	int		n;
// 	double	tmp;

// 	n = 0;
// 	while(n < MAX_ITERATIONS)
// 	{
// 		if((f->z_im * f->z_im + f->z_re * f->z_re) > 4.0)
// 			break;
		
// 		tmp = 2 * f->z_re * f->z_im + f->c_im;
// 		f->z_re = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->c_re;
// 		f->z_im = tmp;
// 		n++;
// 	}
// 	return (n);
// }

/**
 * mandelbrot - Calculates the Mandelbrot set for a given complex number c
 * 
 * The Mandelbrot set is defined by the iterative formula: z(n+1) = z(n)^2 + c
 * where z starts at 0 and c is the complex coordinate being tested.
 * 
 * For each point c in the complex plane:
 * - We start with z = 0
 * - We iterate the formula z = z^2 + c
 * - If |z| > 2 (or |z|^2 > 4), the point escapes to infinity
 * - The number of iterations before escape determines the color
 * - Points that don't escape within MAX_ITERATIONS are part of the Mandelbrot set
 * 
 * @param f: Pointer to fractol structure containing:
 *           - map_x_re, map_y_im: Real and imaginary parts of point c being tested
 *           - z_re, z_im: Real and imaginary parts of z (modified during iteration)
 * 
 * @return: Number of iterations before escape (or MAX_ITERATIONS if no escape)
 */
int mandelbrot(t_fractol *f)
{
	int		n;
	double	tmp;

	n = 0;
	f->z_re = 0;
	f->z_im = 0;
	while(n < MAX_ITERATIONS)
	{
		if((f->z_im * f->z_im + f->z_re * f->z_re) > 4.0)
			break;
		tmp = 2 * f->z_re * f->z_im + f->map_y_im;
		f->z_re = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->map_x_re;
		f->z_im = tmp;
		n++;
	}
	return (n);
}
