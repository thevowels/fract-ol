// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#define WIDTH 720
#define HEIGHT 480
#define BPP sizeof(int32_t)

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int	main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);
	
	mlx_image_t* img = mlx_new_image(mlx,WIDTH,HEIGHT);
	// memset(img->pixels, 255, img->width * img->height * BPP);
	int i;
	int j;
	i = 100;
	while ( i < 300)
	{
		j = 100;
		while(j < 300)
		{
			mlx_put_pixel(img, i, j, 0xFF0000FF);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx,img,0,0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}