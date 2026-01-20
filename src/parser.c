/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 06:22:44 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 05:50:22 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractals.h"


static void	set_julia_constants(t_fractol *f, int ac, char **av)
{
	ft_printf("set_julia constant");
	if (ac == 4)  // Changed: should be exactly 4 args for Julia with constants
	{
		f->c_re = ft_atof(av[2]);
		if (f->c_re > 2.0 || f->c_re < -2.0)
			f->is_error = -1;
		f->c_im = ft_atof(av[3]);
		if (f->c_im > 2.0 || f->c_im < -2.0)
			f->is_error = -1;
	}
	else
		f->is_error = -1;
}

#include <stdio.h>

static void	set_fractal(t_fractol *f, int ac, char **av)
{
	if (*(av[1]) == 'M' || *(av[1]) == 'm')
		f->fractal = &mandelbrot;
	else if (*(av[1]) == 'J' || *(av[1]) == 'j')
	{
		ft_printf("get called set fractal\n");
		f->fractal = &julia;
		if (ac > 2)
			set_julia_constants(f, ac, av);
		else
		{
			f->c_im = -0.095000;
			f->c_re = -0.766667;
			printf("Constants %f && %f\n", f->c_im, f->c_re);
		}
	}
	// else if (ft_strncmp("T", av[1], 1) == 0)
	// 	f->name = "T";
	else
		f->is_error = -1;
}

void parse_args(int argc, char **argv, t_fractol *fractol)
{
	if(argc < 2)
		fractol->is_error = -1;
	else
	{
		set_fractal(fractol, argc, argv);
	}
}