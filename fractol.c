#include "fractol.h"

static void window_runing(t_fractal *fractal, char *name)
{
	init_rendering(fractal, name);
	render_to_window_mandelbrot(0, 0, fractal);
	window_actions(fractal);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
		exit(EXIT_FAILURE);
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
		error_msg(1);
}
