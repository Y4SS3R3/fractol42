/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:38:43 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/05 17:21:31 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>

#define MANDELBROT 1
#define JULIA 2
#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2
#define MOUSE_ZOOM_IN 4
#define MOUSE_ZOOM_OUT 5

typedef struct s_complexe
{
	double x;
	double y;
} t_complexe;

typedef struct s_fractal
{
	t_complexe	c;
	t_complexe	z;
	t_complexe	offset;
	double	zoom;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		iter;
	int		endian;
	void	*init;
	void	*window;
	int		mandelbrot_vs_julia;
	t_complexe	start;
	t_complexe	end;
} t_fractal;

int mandelbrot_study(double x, double y, t_fractal *fractal);
double map(double unscaled_num, double new_min, double new_max, double old_max);
int julia_study(double x, double y, double cx, double cy, t_fractal *fractal);
int	ft_atof(const char *str);
void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
void render_to_window_mandelbrot(int x,int y,t_fractal *fractal);
void	window_actions(t_fractal *fractal);
void render_to_window_julia(int x,int y,t_fractal *fractal);
#endif
