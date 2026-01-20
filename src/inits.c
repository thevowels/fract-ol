/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:50:10 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/20 07:53:13 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "colors.h"
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
	f->c_im = 0.0;
	f->c_re = 0.0;
	f->map_x_re = 0.0;
	f->map_y_im = 0.0;
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = 2.0;
	f->zoom_factor = 1.0;
	f->is_error = 0;
	f->color_pattern = 1;
	f->get_color = &color_pattern_1;
}