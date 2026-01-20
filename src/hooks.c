/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:05:37 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/20 07:31:43 by aphyo-ht         ###   ########.fr       */
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
}
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
	draw(fractol);
}

void	mouse_hook(double xdelta, double ydelta, void *param)
{
	t_fractol *fractol;
	int32_t mouse_x;
	int32_t mouse_y;

	(void)xdelta;
	fractol = (t_fractol *)param;
	mlx_get_mouse_pos(fractol->img.mlx, &mouse_x, &mouse_y);
	if (ydelta < 0)
		zoom(fractol, mouse_x, mouse_y, fractol->zoom_factor);
	else if (ydelta > 0)
		zoom(fractol, mouse_x, mouse_y, 1 / fractol->zoom_factor);
	draw(fractol);
}