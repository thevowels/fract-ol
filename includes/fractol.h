/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:14:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/20 07:47:45 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/includes/libft.h"
# include <math.h>
# include <stdint.h>
# include <stdlib.h>

# ifndef WIDTH
#  define WIDTH 1080
# endif

# ifndef HEIGHT
#  define HEIGHT 960
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 50
# endif

typedef struct s_img
{
	mlx_t					*mlx;
	mlx_image_t				*img;
}							t_img;

/**
 * @struct s_fractol

	* @brief Structure containing fractal rendering data and complex number coordinates
 * @param img Image structure containing MLX instance and image
 * @param x X coordinate for pixel position
 * @param y Y coordinate for pixel position
 * @param z_im Imaginary part of complex number z
 * @param z_re Real part of complex number z
 * @param c_im Imaginary part of complex constant c
 * @param c_re Real part of complex constant c
 */
typedef struct s_fractol	t_fractol;

struct						s_fractol
{
	t_img					img;
	int						n;
	int						x;
	int						y;
	double					z_im;
	double					z_re;
	double					c_im;
	double					c_re;
	double					map_x_re;
	double					map_y_im;
	double					min_r;
	double					max_r;
	double					min_i;
	double					max_i;
	int						is_error;
	int						color_pattern;
	double					zoom_factor;
	int						(*fractal)(t_fractol *f);
	int						(*get_color)(int iterations, int max_iterations);
};

void						init(t_fractol *f);
void						exit_mlx(t_img *img);
void						help_msg(void);
int							get_rgba(int r, int g, int b, int a);
void						parse_args(int argc, char **argv,
								t_fractol *fractol);
#endif