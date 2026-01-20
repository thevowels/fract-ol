/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:29:42 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 06:30:52 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "fractol.h"

static int	clamp_color(int color)
{
	if (color < 0)
		return (0);
	if (color > 255)
		return (255);
	return (color);
}

static int	psychedelic_calc(t_psyche_color *p, double t)
{
	int r, g, b;
	r = p->center + (int)(p->amplitude * sin(p->frequency_r * t + p->phase_r));
	g = p->center + (int)(p->amplitude * sin(p->frequency_g * t + p->phase_g));
	b = p->center + (int)(p->amplitude * sin(p->frequency_b * t + p->phase_b));
	return (get_rgba(clamp_color(r), clamp_color(g), clamp_color(b), 255));
}

// Pattern 1: Ultra-bright rainbow waves
int	color_pattern_1(int iterations, int max_iterations)
{
	int		r;
	int		g;
	int		b;
	double	smooth_iter;

	if (iterations == max_iterations)
		return (get_rgba(0, 0, 0, 255));
	smooth_iter = iterations + 1 - log(log(2)) / log(2.0);
	r = (int)(sin(0.1 * smooth_iter + 1) * 127 + 128);
	g = (int)(sin(0.1 * smooth_iter + 2) * 127 + 128);
	b = (int)(sin(0.1 * smooth_iter + 4) * 127 + 128);
	return (get_rgba(r, g, b, 255));
}
// int	color_pattern_1(int iterations, int max_iterations)
// {
// 	t_psyche_color	p;
// 	double			t;

// 	if (iterations == 0  || iterations == max_iterations)
// 		return (get_rgba(0,0,0, 255));
// 	t = (double)iterations / max_iterations * 12.0;
// 	p = (t_psyche_color){3.0, 5.0, 7.0, 0.0, 2.0, 4.0, 127, 128};
// 	return (psychedelic_calc(&p, t));
// }

// Pattern 2: Neon strobe effect
int	color_pattern_2(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (0x000000FF);
	// Every 10 iterations, the pattern repeats
	int colors[] = {
		0xFF0000FF, // Red
		0x00FF00FF, // Green
		0x0000FFFF, // Blue
		0xFFFF00FF, // Yellow
		0xFF00FFFF  // Magenta
	};
	return (colors[iterations % 5]);
}

// Pattern 3: Acid trip waves
int	color_pattern_3(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / (double)max_iter;
	// Example coefficients to create different gradients
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 24 | g << 16 | b << 8 | 0xFF); // Assuming RGBA (MLX42 style)
}

// Pattern 4: Electric plasma
int	color_pattern_4(int iterations, int max_iterations)
{
	t_psyche_color	p;
	double			t;

	if (iterations == max_iterations)
		return (get_rgba(255, 255, 0, 255));
	t = (double)iterations / max_iterations * 25.0;
	p = (t_psyche_color){15.0, 10.0, 18.0, 0.8, 4.2, 2.1, 180, 75};
	return (psychedelic_calc(&p, t));
}

int	interpolate(int start_color, int end_color, double fraction)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - fraction) * ((start_color >> 24) & 0xFF) + fraction
			* ((end_color >> 24) & 0xFF));
	g = (int)((1 - fraction) * ((start_color >> 16) & 0xFF) + fraction
			* ((end_color >> 16) & 0xFF));
	b = (int)((1 - fraction) * ((start_color >> 8) & 0xFF) + fraction
			* ((end_color >> 8) & 0xFF));
	int a = 0xFF; // Full opacity
	return (r << 24 | g << 16 | b << 8 | a);
}
// Pattern 5: Cosmic rainbow spiral
int	color_pattern_5(int iter, int max_iter)
{
	double	t;

	if (iter == max_iter)
		return (0x000000FF); // Deep black for the set itself
	t = (double)iter / (double)max_iter;
	// Define 3 "key" colors (RGBA for MLX42)
	int color1 = 0x000764FF; // Deep Blue
	int color2 = 0x206BCBFF; // Sky Blue
	int color3 = 0xEDF8FFFF; // Near White
	if (t < 0.5)
		return (interpolate(color1, color2, t * 2)); // First half of iterations
	else
		return (interpolate(color2, color3, (t - 0.5) * 2)); // Second half
}

// Helper function to select psychedelic pattern
int	get_psychedelic_color(int iterations, int max_iterations, int pattern)
{
	if (pattern == 1)
		return (color_pattern_2(iterations, max_iterations));
	else if (pattern == 2)
		return (color_pattern_3(iterations, max_iterations));
	else if (pattern == 3)
		return (color_pattern_4(iterations, max_iterations));
	else if (pattern == 4)
		return (color_pattern_5(iterations, max_iterations));
	else
		return (color_pattern_1(iterations, max_iterations));
	return (color_pattern_1(iterations, max_iterations));
}
