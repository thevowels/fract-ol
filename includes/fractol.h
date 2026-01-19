/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:32:37 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/20 02:30:28 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/includes/libft.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 200
# endif

typedef struct s_img
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_img;

typedef struct s_color_scheme
{
	int	shift;
	int	r_set;
	int	g_set;
	int	b_set;
	int	hue;
	int	saturation;
	int	brightness;
	int	contrast;
	int	c;
	int	x;
	int	m;
	int	r;
	int	g;
	int	b;
	int	palette;
}	t_color_scheme;
typedef struct s_fractol
{
	t_img			img;
	char			*name;
	int				x;
	int				y;
	double			j_ci;
	double			j_cr;
	double			m_zi;
	double			m_zr;
	double			max_i;
	double			max_r;
	double			min_r;
	double			min_i;
	double			pi;
	double			pr;
	int				error;
	int				n;
	double			zoom_factor;
	t_color_scheme	cs;
}	t_fractol;



#endif