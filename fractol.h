/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:38:43 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/14 15:16:16 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>

# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_ZOOM_IN 5
# define MOUSE_ZOOM_OUT 4
# define SPACE 49
# define PLUS 24
# define MINUS 27
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define ESC 53
# define ENTER 36
# define WIDTH 600
# define HEIGHT 600

typedef struct s_complexe
{
	double	x;
	double	y;
}	t_complexe;

typedef struct s_fractal
{
	t_complexe	c;
	t_complexe	z;
	t_complexe	offset;
	double		zoom;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			iter;
	int			iter_max;
	int			endian;
	void		*init;
	void		*window;
	int			fractal;
	t_complexe	start;
	t_complexe	end;
}	t_fractal;

double	scale_it(double unscaled_num,
			double new_min, double new_max, double old_max);
int		mandelbrot_study(double x, double y, t_fractal *fractal);
int		julia_study(double x, double y, t_fractal *fractal);
int		tricorn_study(double x, double y, t_fractal *fractal);
void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
void	window_actions(t_fractal *fractal);
void	render_to_window_tricorn(int x, int y, t_fractal *fractal);
void	render_to_window_mandelbrot(int x, int y, t_fractal *fractal);
void	render_to_window_julia(int x, int y, t_fractal *fractal);
int		ft_close_window(t_fractal *fractal);
int		key_func(int keycode, t_fractal *fractal);
int		mouse_func(int button, int x, int y, t_fractal *fractal);
void	window_actions(t_fractal *fractal);
void	init_rendering(t_fractal *fractal, char *name);
size_t	ft_strcmp(char *s1, char *s2);
void	ft_requiem(t_fractal *fractal);
void	error_msg(void);
int		ft_isdigit(int c);
int		check_input(char *str);
int		ft_check(char c);
void	ft_putstr_fd(char *s, int fd);
double	custom_atof(char *str);
#endif
