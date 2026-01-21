/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:05:37 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 11:43:40 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "colors.h"
#include "fractol.h"

static void	shift_color(t_fractol *f)
{
	if (f->color_pattern == 1)
		f->get_color = color_pattern_2;
	else if (f->color_pattern == 2)
		f->get_color = color_pattern_3;
	else if (f->color_pattern == 3)
		f->get_color = color_pattern_4;
	else if (f->color_pattern == 4)
		f->get_color = color_pattern_5;
	else if (f->color_pattern == 5)
		f->get_color = color_pattern_1;
	if (f->color_pattern < 5)
		f->color_pattern += 1;
	else
		f->color_pattern = 1;
}
// static bool keys_down(mlx_t *mlx, keys_t k1, keys_t k2)
// {
// 	return (mlx_is_key_down(mlx, k1) || mlx_is_key_down(mlx, k2));
// }

// void	keyboard_hook(void *param)
// {
// 	t_fractol *fractol;

// 	fractol = (t_fractol *)param;

// 	if(mlx_is_key_down(fractol->img.mlx, MLX_KEY_ESCAPE))
// 	{
// 		exit_mlx(&fractol->img);
// 		return ;
// 	}
// 	else if(keys_down(fractol->img.mlx, MLX_KEY_UP , MLX_KEY_W))
// 		move(fractol, 0.2, 'U');
// 	else if(keys_down(fractol->img.mlx, MLX_KEY_DOWN , MLX_KEY_S))
// 		move(fractol, 0.2, 'D');
// 	else if(keys_down(fractol->img.mlx, MLX_KEY_LEFT, MLX_KEY_A))
// 		move(fractol, 0.2, 'L');
// 	else if(keys_down(fractol->img.mlx, MLX_KEY_RIGHT, MLX_KEY_D))
// 		move(fractol, 0.2, 'R');
// 	else if(mlx_is_key_down(fractol->img.mlx, MLX_KEY_C))
// 		shift_color(fractol);
// 	else
// 		return ;
// 	return ;
// }
void	keyboard_hook(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		exit_mlx(&fractol->img);
		return ;
	}
	else if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		move(fractol, 0.2, 'U');
	else if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		move(fractol, 0.2, 'D');
	else if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		move(fractol, 0.2, 'L');
	else if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		move(fractol, 0.2, 'R');
	else if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		shift_color(fractol);
	else
		return ;
	fractol->draw(fractol);
}

void	mouse_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	(void)xdelta;
	fractol = (t_fractol *)param;
	mlx_get_mouse_pos(fractol->img.mlx, &(fractol->mouse_x),
		&(fractol->mouse_y));
	if (ydelta < 0 && !fractol->is_zooming)
	{
		fractol->accumulated_zoom += fractol->zoom_factor;
	}
	else if (ydelta > 0 && !fractol->is_zooming)
	{
		fractol->is_zooming = true;
		fractol->accumulated_zoom -= fractol->zoom_factor;
	}
	fractol->last_scroll_time = mlx_get_time();
}

void	frame_hook(void *param)
{
	t_fractol	*fractol;
	double		current_time;

	fractol = (t_fractol *)param;
	current_time = mlx_get_time();
	fractol->is_zooming = true;
	if (fractol->is_zooming && (current_time - fractol->last_scroll_time) > 0.3)
	{
		if (fractol->accumulated_zoom == 0)
		{
			fractol->is_zooming = false;
			return ;
		}
		if (fractol->accumulated_zoom > 0)
			zoom(fractol, fractol->mouse_x, fractol->mouse_y,
				fractol->accumulated_zoom);
		else
			zoom(fractol, fractol->mouse_x, fractol->mouse_y, (1 / (-1
						* fractol->accumulated_zoom)));
		fractol->draw(fractol);
		fractol->accumulated_zoom = 0;
		fractol->is_zooming = false;
	}
}
