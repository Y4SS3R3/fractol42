/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:02:25 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/05 11:02:15 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int mandelbrot_study(double x, double y, t_fractal *fractal)
{
	double		tmp_real;
	int			i;

	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = map(x,fractal->new_min, fractal->new_max, 599) * fractal->zoom + fractal->zoom_offset_x + fractal->offset_x;
	fractal->cy = map(y,fractal->new_min, fractal->new_max, 599) * fractal->zoom + fractal->zoom_offset_y + fractal->offset_y;
	while(i < 200)
	{
		tmp_real = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = tmp_real;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4)
			break ;
		i++;
	}
	return i;
}
