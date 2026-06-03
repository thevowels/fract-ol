/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 03:09:13 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/06/04 03:19:06 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_H
# define EXTRAS_H

# include "fractals.h"

void	put_color_block(t_fractol *f, int block_size);
void	actual_draw_pixelbase(t_fractol *f, int block_size);
void	render_hook(void *param);

#endif