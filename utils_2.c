/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:28:35 by ymassiou          #+#    #+#             */
/*   Updated: 2024/02/08 22:54:18 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	if (fd >= 0)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_check(char c)
{
	if (c == '+' || c == '-' || ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}

int	check_input(char *str)
{
	int	i;
	int	count_digit;
	int	count_dot;

	i = -1;
	count_digit = 0;
	count_dot = 0;
	while (str[++i])
	{
		if (!ft_check(str[i]))
			return (0);
		else if (ft_isdigit(str[i]) && (str[i + 1] == '+' || str[i + 1] == '-'))
			return (0);
		if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '.')
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
			count_digit++;
		if (str[i] == '.')
			count_dot++;
	}
	if (count_digit == 0)
		return (0);
	if (count_dot > 1)
		return (0);
	return (1);
}
