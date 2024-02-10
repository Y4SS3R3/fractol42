/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:15:52 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/10 18:22:23 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static long	ft_atoi(const char *str, int *sign, int *zeros)
{
	size_t				i;
	unsigned long long	n;

	i = 0;
	n = 0;
	*zeros = 0;
	while (str[i] && str[i] == '0')
	{
		++(*zeros);
		i++;
	}
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			*sign = -(*sign);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - 48);
	if ((*sign > 0 && n > INT_MAX) || (*sign < 0 && n > INT_MAX))
		error_msg();
	return (n);
}

double	custom_atof(char *str)
{
	size_t	i;
	double	ne;
	double	nd;
	int		sign;
	int		zeros;

	i = 0;
	ne = 0;
	nd = 0;
	sign = 1;
	if (!check_input(str))
		error_msg();
	ne = ft_atoi(str, &sign, &zeros);
	while (str[i] != '.' && str[i])
		i++;
	if (!str[i])
		return (ne * sign);
	if (str[i + 1] == '-' || str[i + 1] == '+')
		error_msg();
	if (!check_input(&str[++i]))
		error_msg();
	nd = ft_atoi(&str[i], &sign, &zeros);
	while (nd >= 1 || zeros--)
		nd /= 10;
	return ((ne + nd) * sign);
}
