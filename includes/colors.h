/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:52:32 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 05:20:15 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

#include "fractol.h"
#include <math.h>

// Psychedelic color palette struct
typedef struct s_psyche_color
{
	double	frequency_r;
	double	frequency_g;
	double	frequency_b;
	double	phase_r;
	double	phase_g;
	double	phase_b;
	int		amplitude;
	int		center;
}	t_psyche_color;

int	color_pattern_1(int iterations, int max_iterations);
int	color_pattern_2(int iterations, int max_iterations);
int	color_pattern_3(int iterations, int max_iterations);
int	color_pattern_4(int iterations, int max_iterations);
int	color_pattern_5(int iterations, int max_iterations);
#endif