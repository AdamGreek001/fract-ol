/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:24:58 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/07 23:21:10 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_initializer(t_fractol *fractal)
{
	fractal->max_x = 2;
	fractal->min_x = -2;
	fractal->max_y = 2;
	fractal->min_y = -2;
}

int	mouse_press(int button, int x, int y, t_fractol *fractal)
{
	double	frac_center_x;
	double	frac_center_y;

	(void)x;
	(void)y;
	if (button == 4)
	{
		frac_center_x = (fractal->max_x + fractal->min_x) / 2.0;
		frac_center_y = (fractal->max_y + fractal->min_y) / 2.0;
		fractal->max_x = (fractal->max_x - frac_center_x) * 0.9 + frac_center_x;
		fractal->min_x = (fractal->min_x - frac_center_x) * 0.9 + frac_center_x;
		fractal->max_y = (fractal->max_y - frac_center_y) * 0.9 + frac_center_y;
		fractal->min_y = (fractal->min_y - frac_center_y) * 0.9 + frac_center_y;
	}
	else if (button == 5)
	{
		frac_center_x = (fractal->max_x + fractal->min_x) / 2.0;
		frac_center_y = (fractal->max_y + fractal->min_y) / 2.0;
		fractal->max_x = (fractal->max_x - frac_center_x) * 1.1 + frac_center_x;
		fractal->min_x = (fractal->min_x - frac_center_x) * 1.1 + frac_center_x;
		fractal->max_y = (fractal->max_y - frac_center_y) * 1.1 + frac_center_y;
		fractal->min_y = (fractal->min_y - frac_center_y) * 1.1 + frac_center_y;
	}
	start_draw(fractal);
	return (1);
}

int	destroy_window(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->window_ptr);
	free(fractal);
	exit(0);
}

int	key_press(int key, t_fractol *fractal)
{
	if (key == 53)
		destroy_window(fractal);
	return (0);
}
