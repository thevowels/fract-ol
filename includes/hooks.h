/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:03:35 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 10:09:58 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "fractol.h"

void	keyboard_hook(mlx_key_data_t key, void *param);
void	mouse_hook(double xdelta, double ydelta, void *param);
void	frame_hook(void *param);
#endif