/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:57:22 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/01/21 09:56:37 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "colors.h"

void	help_msg(void)
{
	ft_printf("⊱ ───────────────── {.⋅ Fractol ⋅.} ───────────────── ⊰\n\n");
	ft_printf("Which fractal would you like to see?\n");
	ft_printf("M - Mandelbrot    ");
	ft_printf("J - Julia    ");
	ft_printf("T - Tricorn\n\n");
	ft_printf("\e[36mUsage example:\t./fractol <type>\n\t\t./fractol \
	M\e[0m\n\n");
	ft_printf("\nFor Julia, you may specify starting values which should be betw\
	een -2.0 and 2.0.\n");
	ft_printf("\e[36mUsage example:\t");
	ft_printf("./fractol J\n\t\t./fractol J 0.285 0.01\n");
	ft_printf("\t\t./fractol J -0.4 0.6\n");
	ft_printf("\t\t./fractol J -1.476 0.0\n");
	ft_printf("\t\t./fractol J 0.3 -0.01\e[0m\n\n");
}

void	exit_mlx(t_img *img)
{
	mlx_delete_image(img->mlx, img->img);
	mlx_close_window(img->mlx);
	mlx_terminate(img->mlx);
	exit(EXIT_SUCCESS);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_psychedelic_color(int iterations, int max_iterations, int pattern)
{
	if (pattern == 1)
		return (color_pattern_1(iterations, max_iterations));
	else if (pattern == 2)
		return (color_pattern_2(iterations, max_iterations));
	else if (pattern == 3)
		return (color_pattern_3(iterations, max_iterations));
	else if (pattern == 4)
		return (color_pattern_4(iterations, max_iterations));
	else if (pattern == 5)
		return (color_pattern_5(iterations, max_iterations));
	return (color_pattern_1(iterations, max_iterations));
}
