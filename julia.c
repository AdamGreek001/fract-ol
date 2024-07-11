/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:24:46 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/09 23:43:43 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_initial_z(t_fractol *fractal, t_complx *z, int x, int y)
{
	z->real = fractal->min_x + x / (double)WIDTH * (fractal->max_x
			- fractal->min_x);
	z->imag = (fractal->min_y + (HEIGHT - y) / (double)HEIGHT * (fractal->max_y
				- fractal->min_y));
}

void	set_initial_c(t_fractol *fractal, t_complx *c)
{
	if (fractal->fractol_type == 3)
	{
		c->real = fractal->real;
		c->imag = fractal->imag;
	}
	else
	{
		c->real = REAL_PA;
		c->imag = IMAG_PA;
	}
}

void	iterate_julia(t_fractol *fractal, t_complx *z, t_complx *c)
{
	t_complx	tmp;

	while (z->real * z->real + z->imag * z->imag < 4
		&& fractal->iteration < MAXITERATION)
	{
		tmp.real = z->real * z->real - z->imag * z->imag + c->real;
		tmp.imag = 2 * z->real * z->imag + c->imag;
		*z = tmp;
		fractal->iteration++;
	}
}

void	julia_algo(t_fractol *fractal, int x, int y)
{
	t_complx	z;
	t_complx	c;

	fractal->iteration = 1;
	set_initial_z(fractal, &z, x, y);
	set_initial_c(fractal, &c);
	iterate_julia(fractal, &z, &c);
}

void	my_julia_fractal(t_fractol *fractal)
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
			julia_algo(fractal, x, y);
			if (fractal->iteration == MAXITERATION)
				color = 0x0f000f;
			else
				color = 0x0c0003 * (fractal->iteration * 65 + 1);
			my_mlx_pixel_put(fractal, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->window_ptr,
		fractal->img_ptr, 0, 0);
}
