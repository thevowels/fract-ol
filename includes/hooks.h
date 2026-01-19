/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 01:23:02 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/20 02:29:35 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "fractol.h"

void		zoom(t_fractol *fractol, int x, int y, double zoom_factor);
void		move(t_fractol *f, double distance, char direction);
void		handle_mouse(double xdelta, double ydelta, void *param);
void		handel_keyboard(mlx_key_data_t key, void *param);

#endif