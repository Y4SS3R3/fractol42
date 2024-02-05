#include "fractol.h"
#include <stdio.h>

double map(double unscaled_num, double new_min, double new_max, double old_max)
{
    return (new_max - new_min) * unscaled_num / old_max + new_min;
}

int julia_study(double x, double y, double cx, double cy, t_fractal *fractal)
{
	double		tmp_real;
	int			i;

	i = 0;
	// cordx *= 0.5
	// cordx += x;
	fractal->zx = map(x,-2, 2, 599) * fractal->zoom + fractal->offset_x;
	fractal->zy = map(y,-2, 2, 599) * fractal->zoom + fractal->offset_y;
	fractal->cx = cx;
	fractal->cy = cy;
	while(i < 100)
	{
		tmp_real = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2 * tmp_real * fractal->zy + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4)
			break ;
		i++;
	}
	return i;
}
