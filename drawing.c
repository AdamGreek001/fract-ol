/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:24:43 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/07 23:33:44 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *fractal, int x, int y, int color)
{
	fractal->address[y * WIDTH + x] = color;
}

void	start_draw(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	fractal->address = (int *)mlx_get_data_addr(fractal->img_ptr,
			&fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
	if (fractal->fractol_type == 1)
	{
		my_mandelbrot_fractal(fractal);
	}
	else if (fractal->fractol_type == 2 || fractal->fractol_type == 3)
		my_julia_fractal(fractal);
}

void	ft_draw(t_fractol *fractal)
{
	fractal->mlx_ptr = mlx_init();
	fractal->window_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			"fractal");
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	fractal->address = (int *)mlx_get_data_addr(fractal->img_ptr,
			&fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
	start_draw(fractal);
	mlx_hook(fractal->window_ptr, 4, 0, mouse_press, (void *)fractal);
	mlx_hook(fractal->window_ptr, 17, 0, destroy_window, (void *)fractal);
	mlx_hook(fractal->window_ptr, 3, 0, key_press, (void *)fractal);
	mlx_loop(fractal->mlx_ptr);
}
