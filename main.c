/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:24:49 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/07 23:22:52 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_checker(t_fractol *fractal, char **av)
{
	if (!check_num(av[2]) || !check_num(av[3]))
	{
		fractol_types();
		free(fractal);
		exit(1);
	}
	fractal->fractol_type = 3;
	fractal->real = ft_atof(av[2]);
	fractal->imag = ft_atof(av[3]);
	if (fabs(fractal->real) > 2 || fabs(fractal->imag) > 2)
	{
		fractol_types();
		free(fractal);
		exit(1);
	}
}

void	parse_args(t_fractol *fractal, int ac, char **av)
{
	if (!ft_strncmp(av[1], "mandelbrot", 10) && ac == 2)
		fractal->fractol_type = 1;
	else if (!ft_strncmp(av[1], "julia", 5) && (ac == 4))
	{
		if (ac == 4)
			julia_checker(fractal, av);
		else
			fractal->fractol_type = 2;
	}
	else
	{
		fractol_types();
		free(fractal);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_fractol	*fractal;

	if (ac < 2)
	{
		fractol_types();
		return (1);
	}
	fractal = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractal)
		return (1);
	parse_args(fractal, ac, av);
	fractal_initializer(fractal);
	ft_draw(fractal);
	return (0);
}
