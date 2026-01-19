/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:35:37 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/20 01:22:18 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

#include "fractol.h"

int	julia_set(t_fractol *f);
int	mandelbrot_set(t_fractol *f);
int	tricorn_set(t_fractol *f);


#endif