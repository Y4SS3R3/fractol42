/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:56:03 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/07 11:56:09 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void render_to_window_julia(int x,int y,t_fractal *fractal)
{
	int i;
	int red;
	int green;
	int blue;

	while (x < 600)
	{
		y = 0;
		while (y < 600)
		{
			i = julia_study(x, y, fractal->c.x, fractal->c.y, fractal);
			if (i == fractal->iter_max)
				my_mlx_pixel_put(fractal, x, y, 0x000000);
			else
			{
				red = (i * 1 * fractal->iter) %255;
				green = (i * 3 * fractal->iter) %255;
				blue = (i * 5 * fractal->iter) %255;
				my_mlx_pixel_put(fractal, x, y, (red << 16) | (green << 8) | blue );
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->init, fractal->window, fractal->img, 0, 0);
}

int julia_study(double x, double y, double cx, double cy, t_fractal *fractal)
{
	double		tmp_real;
	int			i;

	i = 0;
	fractal->z.x = map(x,fractal->start.x, fractal->end.x, 599) + fractal->offset.x;
	fractal->z.y = map(y,fractal->start.y, fractal->end.y, 599) + fractal->offset.y;
	fractal->c.x = cx;
	fractal->c.y = cy;
	while(i < fractal->iter_max)
	{
		tmp_real = fractal->z.x;
		fractal->z.x = fractal->z.x * fractal->z.x - fractal->z.y * fractal->z.y + fractal->c.x;
		fractal->z.y = 2 * tmp_real * fractal->z.y + fractal->c.y;
		if (fractal->z.x * fractal->z.x + fractal->z.y * fractal->z.y >= 4)
			break ;
		i++;
	}
	return i;
}
