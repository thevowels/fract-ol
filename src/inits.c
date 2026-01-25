/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:50:10 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/25 19:05:44 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "fractol.h"

/**
 * init - Initializes all values in the t_fractol structure
 *
 * Sets up default values for fractal rendering including:
 * - Complex plane coordinate mappings
 * - Zoom and view parameters
 * - Complex number components for calculations
 * - Image structure initialization
 * - Error state management
 *
 * @param f: Pointer to fractol structure to initialize
 */
void	init(t_fractol *f)
{
	f->n = 0;
	f->x = 0;
	f->y = 0;
	f->z_im = 0.0;
	f->z_re = 0.0;
	f->c_im = -0.095000;
	f->c_re = -0.766667;
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = 2.0;
	f->zoom_factor = 2.0;
	f->is_error = 0;
	f->color_pattern = 2;
	f->get_color = &color_pattern_2;
	f->inv_max = 1 / MAX_ITERATIONS;
	f->last_scroll_time = 1;
	f->accumulated_zoom = 0;
	f->is_zooming = false;
	f->width = WIDTH;
	f->height = HEIGHT;
	mlx_image_to_window(f->img.mlx, f->img.img, 0, 0);
}
