/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:41:15 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/10 09:40:42 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(int flag)
{
	ft_putstr_fd("Available fractals :\n", 1);
	ft_putstr_fd("\t=> mandelbrot <=\n\n", 1);
	ft_putstr_fd("\t=> julia (2 additionnal parametres) <=\n\n", 1);
	ft_putstr_fd("\t=> tricorn <=\n", 1);
	if (flag == 1)
		exit(EXIT_FAILURE);
}

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

size_t	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_requiem(t_fractal *fractal)
{
	fractal->iter = 1;
	fractal->offset.x = 0.0;
	fractal->offset.y = 0.0;
	fractal->zoom = 1.0;
	fractal->start.x = -2;
	fractal->end.x = 2;
	fractal->start.y = 2;
	fractal->end.y = -2;
	fractal->iter_max = 100;
}

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr;
	dst += (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
