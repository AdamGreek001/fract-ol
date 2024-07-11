/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:25:01 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/07 23:05:00 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(char c)
{
	while (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

double	check_it(char *s, int i)
{
	double	power;
	double	value;

	power = 1.0;
	value = 0.0;
	while (ft_isdigit(s[i]))
	{
		value = 10.0 * value + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		value = 10.0 * value + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (value / power);
}

double	ft_atof(char *str)
{
	int		sign;
	int		i;
	double	result;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	result = check_it(str, i);
	return (sign * result);
}

int	check_num(char *str)
{
	size_t	i;
	int		c_dot;

	i = 0;
	c_dot = 0;
	if (str[i + 1] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.'))
	{
		if (str[i] == '.')
			c_dot++;
		i++;
	}
	if (c_dot != 1 || i != ft_strlen(str))
		return (0);
	else
		return (1);
}
