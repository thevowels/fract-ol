/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:29:42 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 12:12:48 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "fractol.h"
#include <math.h>

int	color_pattern_1(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (0x000000FF);
	return (0xFF8080FF);
}

int	color_pattern_2(int i, int max_i)
{
	if (i == max_i)
		return (0x000000FF);
	return (get_rgba(i, i, i + 50, 255));
}

int	color_pattern_3(int i, int max_i)
{
	double	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
	g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (get_rgba(r, g, b, 255));
}

int	color_pattern_4(int i, int max_i)
{
	double	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	if (i == max_i)
		return (0x000000FF);
	t = sqrt((double)i / max_i);
	r = (uint8_t)(t * 50);
	g = (uint8_t)(t * 255);
	b = (uint8_t)(50 + t * 205);
	return (get_rgba(r, g, b, 255));
}

int	color_pattern_5(int i, int max_i)
{
	double	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	if (i == max_i)
		return (0x000000FF);
	t = (double)i / max_i;
	r = (uint8_t)(255 * (0.5 * (1 + cos(6.28 * (t + 0.00)))));
	g = (uint8_t)(255 * (0.5 * (1 + cos(6.28 * (t + 0.10)))));
	b = (uint8_t)(255 * (0.5 * (1 + cos(6.28 * (t + 0.20)))));
	return (get_rgba(r, g, b, 255));
}
