/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:29:42 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 02:18:37 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// Pattern 1: Blue to Red gradient
int	color_pattern_1(int iterations, int max_iterations)
{
	double	t;
	int		r, g, b;

	if (iterations == max_iterations)
		return (get_rgba(0, 0, 0, 255));
	t = (double)iterations / max_iterations;
	r = (int)(255 * t);
	g = (int)(128 * (1 - t));
	b = (int)(255 * (1 - t));
	return (get_rgba(r, g, b, 255));
	// if (iterations == max_iterations)
	// 	return (get_rgba(255, 0, 0, 255));

	// int intensity = (iterations * 255) / max_iterations;
	// (void)intensity;
	// return (get_rgba(255, 0, 0, 255));

}

// Pattern 2: Fire gradient
int	color_pattern_2(int iterations, int max_iterations)
{
	double	t;
	int		r, g, b;

	if (iterations == max_iterations)
		return (get_rgba(0, 0, 0, 255));
	t = (double)iterations / max_iterations;
	r = 255;
	g = (int)(255 * t);
	b = (int)(128 * t * t);
	return (get_rgba(r, g, b, 255));
}

// Pattern 3: Psychedelic cycling
int	color_pattern_3(int iterations, int max_iterations)
{
	double	t;
	int		r, g, b;

	if (iterations == max_iterations)
		return (get_rgba(255, 0, 255, 255));
	t = (double)iterations / max_iterations * 6.28;
	r = (int)(128 + 127 * ((int)(t * 2) % 2 ? 1 : -1));
	g = (int)(128 + 127 * ((int)(t * 3) % 2 ? 1 : -1));
	b = (int)(128 + 127 * ((int)(t * 4) % 2 ? 1 : -1));
	return (get_rgba(r, g, b, 255));
}

// Pattern 4: Ocean waves
int	color_pattern_4(int iterations, int max_iterations)
{
	double	t;
	int		r, g, b;

	if (iterations == max_iterations)
		return (get_rgba(0, 17, 34, 255));
	t = (double)iterations / max_iterations;
	r = (int)(50 * t);
	g = (int)(100 + 155 * t);
	b = (int)(200 + 55 * (1 - t));
	return (get_rgba(r, g, b, 255));
}

// Pattern 5: Neon green
int	color_pattern_5(int iterations, int max_iterations)
{
	double	t;
	int		r, g, b;

	if (iterations == max_iterations)
		return (get_rgba(0, 255, 0, 255));
	t = (double)iterations / max_iterations;
	r = (int)(255 * t * t);
	g = (int)(255 - 100 * t);
	b = (int)(50 + 205 * t);
	return (get_rgba(r, g, b, 255));
}

// Helper function to select pattern
// int	get_color(int iterations, int max_iterations, int pattern)
// {
// 	if (pattern == 1)
// 		return (color_pattern_1(iterations, max_iterations));
// 	else if (pattern == 2)
// 		return (color_pattern_2(iterations, max_iterations));
// 	else if (pattern == 3)
// 		return (color_pattern_3(iterations, max_iterations));
// 	else if (pattern == 4)
// 		return (color_pattern_4(iterations, max_iterations));
// 	else if (pattern == 5)
// 		return (color_pattern_5(iterations, max_iterations));
// 	return (color_pattern_1(iterations, max_iterations));
// }

