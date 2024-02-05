/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:02:25 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/05 17:19:57 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int mandelbrot_study(double x, double y, t_fractal *fractal)
{
	double		tmp_real;
	int			i;

	i = 0;
	fractal->z.x = 0.0;
	fractal->z.y = 0.0;
	fractal->c.x = map(x,fractal->start.x, fractal->end.x, 599) * fractal->zoom + fractal->offset.x;
	fractal->c.y = map(y,fractal->start.y, fractal->end.y, 599) * fractal->zoom + fractal->offset.y;
	while(i < 100)
	{
		tmp_real = fractal->z.x * fractal->z.x - fractal->z.y * fractal->z.y + fractal->c.x;
		fractal->z.y = 2 * fractal->z.x * fractal->z.y + fractal->c.y;
		fractal->z.x = tmp_real;
		if (fractal->z.x * fractal->z.x + fractal->z.y * fractal->z.y >= 4)
			break ;
		i++;
	}
	return i;
}
