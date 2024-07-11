/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:24:52 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/10 01:52:34 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_algo(t_fractol *fractal, int x, int y)
{
	t_complx	z;
	t_complx	tmp;
	t_complx	c;

	fractal->iteration = 1;
	c.real = fractal->min_x + x / (double)WIDTH * (fractal->max_x
			- fractal->min_x);
	c.imag = fractal->min_y + y / (double)HEIGHT * (fractal->max_y
			- fractal->min_y);
	z.real = 0.0;
	z.imag = 0.0;
	tmp = z;
	while (z.real * z.real + z.imag * z.imag < 4
		&& fractal->iteration < MAXITERATION)
	{
		tmp.real = z.real * z.real - z.imag * z.imag + c.real;
		tmp.imag = 2 * z.real * z.imag + c.imag;
		z = tmp;
		fractal->iteration++;
	}
}

void	my_mandelbrot_fractal(t_fractol *fractal)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot_algo(fractal, x, y);
			if (fractal->iteration == MAXITERATION)
				color = 0x000000;
			else
				color = 0x0c2120 * fractal->iteration;
			my_mlx_pixel_put(fractal, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->window_ptr,
		fractal->img_ptr, 0, 0);
}
