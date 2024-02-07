/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:00:57 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/07 11:38:12 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void render_to_window_tricorn(int x,int y,t_fractal *fractal)
{
	int i;
	int red;
	int green;
	int blue;

	while (y < 600)
	{
		x = 0;
		while (x < 600)
		{
			i = tricorn_study(x, y, fractal);
			if (i == fractal->iter_max)
				my_mlx_pixel_put(fractal, x, y, 0x000000);
			else
			{
				red = (i * 1 * fractal->iter) % 255;
				green = (i * 3 * fractal->iter) % 255;
				blue = (i * 5 * fractal->iter) % 255;
				my_mlx_pixel_put(fractal, x, y, (red << 16) | (green << 8) | blue );
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->init, fractal->window, fractal->img, 0, 0);
}

int tricorn_study(double x, double y, t_fractal *fractal)
{
	double		tmp_real;
	int			i;

	i = 0;
	fractal->z.x = 0.0;
	fractal->z.y = 0.0;
	fractal->c.x = map(x,fractal->start.x, fractal->end.x, 599) + fractal->offset.x;
	fractal->c.y = map(y,fractal->start.y, fractal->end.y, 599) + fractal->offset.y;
	while(i < fractal->iter_max)
	{
		tmp_real = fractal->z.x * fractal->z.x - fractal->z.y * fractal->z.y + fractal->c.x;
		fractal->z.y = -2 * fractal->z.x * fractal->z.y + fractal->c.y;
		fractal->z.x = tmp_real;
		if (fractal->z.x * fractal->z.x + fractal->z.y * fractal->z.y >= 4.0)
			break ;
		i++;
	}
	return i;
}
