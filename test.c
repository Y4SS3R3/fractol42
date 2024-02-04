#include "fractol.h"

int	key_func(int keycode, t_fractal *fractal)
{
	if (keycode == 24)
		fractal->max_iter += 10;
	else if (keycode == 27)
		fractal->max_iter -= 10;
	else if (keycode == 123)
		fractal->offset_x += 0.5;
	else if (keycode == 124)
		fractal->offset_x -= 0.5;
	else if (keycode == 126)
		fractal->offset_y += 0.5;
	else if (keycode == 125)
		fractal->offset_y -= 0.5;
	else if (keycode == 53)
		exit(0);
	if (fractal->mandelbrot_vs_julia == MANDELBROT)
		render_to_window_mandelbrot(0, 0, fractal);
	else if (fractal->mandelbrot_vs_julia == JULIA)
		render_to_window_julia(0, 0, fractal);
	return (0);
}

void	init_rendering(t_fractal *fractal ,char *name)
{
	fractal->init = mlx_init();
	fractal->window = mlx_new_window(fractal->init, 1080, 1080, name);
	fractal->img = mlx_new_image(fractal->init, 1080, 1080);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length,
	&fractal->endian);
	fractal->max_iter = 200;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
}

void	window_actions(t_fractal *fractal)
{
	mlx_hook(fractal->window, 2, 0, key_func, fractal);
	mlx_loop(fractal->init);
}

void render_to_window_mandelbrot(int x,int y,t_fractal *fractal)
{
	int i;

	while (x < 1080)
	{
		y = 0;
		while (y < 1080)
		{
			i = mandelbrot_study(x, y, fractal);
			if (i == fractal->max_iter)
				my_mlx_pixel_put(fractal, x, y, 0x000000);
			else
				my_mlx_pixel_put(fractal, x, y, 0xFCBE11 * i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->init, fractal->window, fractal->img, 0, 0);
}

void render_to_window_julia(int x,int y,t_fractal *fractal)
{
	int i;
	int red;
	int green;
	int blue;

	while (x < 1080)
	{
		y = 0;
		while (y < 1080)
		{
			i = julia_study(x, y, fractal->cx, fractal->cy, fractal);
			if (i == fractal->max_iter)
				my_mlx_pixel_put(fractal, x, y, 0x000000);
			else
			{
				red = (i * 1) % 255;
				green = (i * 3) % 255;
				blue = (i * 5) % 255;
				my_mlx_pixel_put(fractal, x, y, (red << 16) | (green << 8) | blue);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->init, fractal->window, fractal->img, 0, 0);
}

size_t	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	float			x;
	float			y;
	int				i;
	int				red;
	int				green;
	int				blue;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		fractal.mandelbrot_vs_julia = MANDELBROT;
		init_rendering(&fractal, "Mandelbrot");
		render_to_window_mandelbrot(0, 0, &fractal);
		window_actions(&fractal);
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		fractal.cx = atof(av[2]);
		fractal.cy = atof(av[3]);
		fractal.mandelbrot_vs_julia = JULIA;
		init_rendering(&fractal, "Julia");
		render_to_window_julia(0, 0, &fractal);
		window_actions(&fractal);
	}
}
