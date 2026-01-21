/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 07:06:11 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 12:09:00 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "fractol.h"

void	draw_pointbase(t_fractol *f);
void	draw_pixelbase(t_fractol *f);
void	zoom(t_fractol *f, int x, int y, double zoom_factor);
void	move(t_fractol *f, double distance, char direction);
void	leaf_choice(t_leaf *leaf, t_fractol *f);
void	leaf_generator(t_fractol *f);
#endif