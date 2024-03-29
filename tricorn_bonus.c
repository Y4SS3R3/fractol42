/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:00:57 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/14 15:11:02 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_to_window_tricorn(int x, int y, t_fractal *fractal)
{
	int	i;
	int	red;
	int	green;
	int	blue;
	int	color;

	while (++y < WIDTH)
	{
		x = -1;
		while (++x < HEIGHT)
		{
			i = tricorn_study(x, y, fractal);
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

int	tricorn_study(double x, double y, t_fractal *fractal)
{
	double		tmp_real;
	int			i;

	if (fractal->iter_max > 200 || fractal->iter_max < 0)
		fractal->iter_max = 200;
	i = 0;
	fractal->z.x = 0.0;
	fractal->z.y = 0.0;
	fractal->c.x = scale_it(x, fractal->start.x, fractal->end.x, WIDTH - 1);
	fractal->c.x += fractal->offset.x;
	fractal->c.y = scale_it(y, fractal->start.y, fractal->end.y, HEIGHT - 1);
	fractal->c.y += fractal->offset.y;
	while (i < fractal->iter_max)
	{
		tmp_real = fractal->z.x * fractal->z.x - fractal->z.y * fractal->z.y;
		tmp_real += fractal->c.x;
		fractal->z.y = -2 * fractal->z.x * fractal->z.y + fractal->c.y;
		fractal->z.x = tmp_real;
		if (fractal->z.x * fractal->z.x + fractal->z.y * fractal->z.y >= 4.0)
			break ;
		i++;
	}
	return (i);
}
