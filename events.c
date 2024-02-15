/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:44:37 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/14 15:11:02 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->init, fractal->img);
	mlx_destroy_window(fractal->init, fractal->window);
	exit(0);
	return (0);
}

int	key_func(int keycode, t_fractal *fractal)
{
	if (keycode == SPACE)
		fractal->iter += 10;
	else if (keycode == MINUS)
		fractal->iter_max -= 5;
	else if (keycode == PLUS)
		fractal->iter_max += 5;
	else if (keycode == ENTER)
		ft_requiem(fractal);
	else if (keycode == LEFT)
		fractal->offset.x -= 0.2 * fractal->zoom;
	else if (keycode == RIGHT)
		fractal->offset.x += 0.2 * fractal->zoom;
	else if (keycode == UP)
		fractal->offset.y += 0.2 * fractal->zoom;
	else if (keycode == DOWN)
		fractal->offset.y -= 0.2 * fractal->zoom;
	else if (keycode == ESC)
		ft_close_window(fractal);
	if (fractal->fractal == MANDELBROT)
		render_to_window_mandelbrot(0, 0, fractal);
	else if (fractal->fractal == JULIA)
		render_to_window_julia(0, 0, fractal);
	else if (fractal->fractal == TRICORN)
		render_to_window_tricorn(0, 0, fractal);
	return (0);
}

int	mouse_func(int button, int x, int y, t_fractal *fractal)
{
	double	zoom;
	double	mousex;
	double	mousey;

	if (button == MOUSE_ZOOM_IN || button == MOUSE_ZOOM_OUT)
	{
		mousex = scale_it(x, fractal->start.x, fractal->end.x, WIDTH - 1);
		mousey = scale_it(y, fractal->start.y, fractal->end.y, HEIGHT - 1);
		if (button == MOUSE_ZOOM_IN)
			zoom = 0.8;
		else
			zoom = 1.2;
		fractal->zoom *= zoom;
		fractal->start.x = (fractal->start.x - mousex) * zoom + mousex;
		fractal->start.y = (fractal->start.y - mousey) * zoom + mousey;
		fractal->end.x = (fractal->end.x - mousex) * zoom + mousex;
		fractal->end.y = (fractal->end.y - mousey) * zoom + mousey;
		if (fractal->fractal == MANDELBROT)
			render_to_window_mandelbrot(0, 0, fractal);
		else if (fractal->fractal == JULIA)
			render_to_window_julia(0, 0, fractal);
		else if (fractal->fractal == TRICORN)
			render_to_window_tricorn(0, 0, fractal);
	}
	return (0);
}

void	window_actions(t_fractal *fractal)
{
	mlx_hook(fractal->window, 2, 0, key_func, fractal);
	mlx_hook(fractal->window, 4, 0, mouse_func, fractal);
	mlx_hook(fractal->window, 17, 0, ft_close_window, fractal);
	mlx_loop(fractal->init);
}

void	init_rendering(t_fractal *fractal, char *name)
{
	fractal->init = mlx_init();
	if (fractal->init == NULL)
		exit(EXIT_FAILURE);
	fractal->window = mlx_new_window(fractal->init, WIDTH, HEIGHT, name);
	if (fractal->window == NULL)
	{
		mlx_destroy_window(fractal->init, fractal->window);
		exit(EXIT_FAILURE);
	}
	fractal->img = mlx_new_image(fractal->init, WIDTH, HEIGHT);
	if (fractal->img == NULL)
	{
		mlx_destroy_image(fractal->init, fractal->img);
		mlx_destroy_window(fractal->init, fractal->window);
		exit(EXIT_FAILURE);
	}
	fractal->addr = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel, &fractal->line_length,
			&fractal->endian);
	ft_requiem(fractal);
}
