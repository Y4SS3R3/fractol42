/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:56:03 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/10 18:39:55 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_to_window_julia(int x, int y, t_fractal *fractal)
{
	int	i;
	int	red;
	int	green;
	int	blue;
	int	color;

	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			i = julia_study(x, y, fractal);
			if (i == fractal->iter_max)
				my_mlx_pixel_put(fractal, x, y, 0x000000);
			else
			{
				red = (i * 1 * fractal->iter) % 255;
				green = (i * 3 * fractal->iter) % 255;
				blue = (i * 5 * fractal->iter) % 255;
				color = (red << 16) | (green << 8) | blue;
				my_mlx_pixel_put(fractal, x, y, color);
			}
		}
	}
	mlx_put_image_to_window(fractal->init, fractal->window, fractal->img, 0, 0);
}

int	julia_study(double x, double y, t_fractal *fractal)
{
	double		tmp_real;
	int			i;

	if (fractal->iter_max > 200)
		fractal->iter_max = 200;
	i = 0;
	fractal->z.x = map(x, fractal->start.x, fractal->end.x, WIDTH - 1);
	fractal->z.x += fractal->offset.x;
	fractal->z.y = map(y, fractal->start.y, fractal->end.y, HEIGHT - 1);
	fractal->z.y += fractal->offset.y;
	while (i < fractal->iter_max)
	{
		tmp_real = fractal->z.x;
		fractal->z.x = fractal->z.x * fractal->z.x;
		fractal->z.x -= fractal->z.y * fractal->z.y;
		fractal->z.x += fractal->c.x;
		fractal->z.y = 2 * tmp_real * fractal->z.y + fractal->c.y;
		if (fractal->z.x * fractal->z.x + fractal->z.y * fractal->z.y >= 4)
			break ;
		i++;
	}
	return (i);
}
