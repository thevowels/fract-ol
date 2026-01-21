/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:14:30 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 12:25:20 by aphyo-ht         ###   ########.fr       */
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
#  define HEIGHT 720
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 200
# endif

typedef struct s_img
{
	mlx_t					*mlx;
	mlx_image_t				*img;
}							t_img;

typedef struct s_fractol	t_fractol;

struct						s_fractol
{
	t_img					img;
	int						n;
	int						x;
	int						y;
	int						width;
	int						height;
	double					inv_max;
	double					z_im;
	double					z_re;
	double					c_im;
	double					c_re;
	double					min_r;
	double					max_r;
	double					min_i;
	double					max_i;
	int						is_error;
	int						color_pattern;
	double					zoom_factor;
	void					(*draw)(t_fractol *f);
	int						(*fractal)(t_fractol *f);
	int						(*get_color)(int iterations, int max_iterations);
	double					last_scroll_time;
	double					accumulated_zoom;
	bool					is_zooming;
	int32_t					mouse_x;
	int32_t					mouse_y;
};

typedef struct s_leaf
{
	double					next_x;
	double					next_y;
	double					r;
	int						px;
	int						py;

}							t_leaf;
void						init(t_fractol *f);
void						exit_mlx(t_img *img);
void						help_msg(void);
int							get_rgba(int r, int g, int b, int a);
void						parse_args(int argc, char **argv,
								t_fractol *fractol);
#endif