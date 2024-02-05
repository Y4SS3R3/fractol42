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
	fractal->z.x = map(x,-2, 2, 599) * fractal->zoom + fractal->offset.x;
	fractal->z.y = map(y,-2, 2, 599) * fractal->zoom + fractal->offset.y;
	fractal->c.x = cx;
	fractal->c.y = cy;
	while(i < 80)
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
