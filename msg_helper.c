/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:24:55 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/07 23:23:25 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_types(void)
{
	printf("fractol: error: invalid arguments\n");
	printf("Available Fractals:\n");
	printf("for mandelbrot\n");
	printf("Usage: ./fractol { \"mandelbrot\n");
	printf("for julia\n");
	printf("Usage: ./fractol { \"julia\" {real} {imag}\n");
}
