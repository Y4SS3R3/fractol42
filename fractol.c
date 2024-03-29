/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:51:36 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/14 15:13:34 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_dimensions(int dimension, char c)
{
	if (c == 'W' && (dimension <= 0 || dimension > 2560))
		return (0);
	if (c == 'H' && (dimension <= 0 || dimension > 1440))
		return (0);
	return (1);
}

static void	window_runing(t_fractal *fractal, char *name)
{
	init_rendering(fractal, name);
	if (*name == 'M')
		render_to_window_mandelbrot(-1, -1, fractal);
	else if (*name == 'J')
		render_to_window_julia(-1, -1, fractal);
	else if (*name == 'T')
		render_to_window_tricorn(-1, -1, fractal);
	window_actions(fractal);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
		error_msg();
	if (!valid_dimensions(HEIGHT, 'H') || !valid_dimensions(WIDTH, 'W'))
		error_msg();
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		fractal.fractal = MANDELBROT;
		window_runing(&fractal, "Mandelbrot");
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		fractal.c.x = custom_atof(av[2]);
		fractal.c.y = custom_atof(av[3]);
		fractal.fractal = JULIA;
		window_runing(&fractal, "Julia");
	}
	else if (ac == 2 && ft_strcmp(av[1], "tricorn") == 0)
	{
		fractal.fractal = TRICORN;
		window_runing(&fractal, "Tricorn");
	}
	else
		error_msg();
}
