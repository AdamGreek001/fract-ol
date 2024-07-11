/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-alao <eel-alao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:24:39 by eel-alao          #+#    #+#             */
/*   Updated: 2024/07/08 22:29:03 by eel-alao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAXITERATION 100
# define REAL_PA 0.025
# define IMAG_PA 1.02

typedef struct s_fractol
{
	void	*window_ptr;
	void	*img_ptr;
	void	*mlx_ptr;
	int		*address;
	int		bits_per_pixel;
	int		line_length;
	int		fractol_type;
	int		endian;
	int		iteration;
	double	max_y;
	double	min_y;
	double	min_x;
	double	max_x;
	double	imag;
	double	real;
}			t_fractol;

typedef struct s_complx
{
	double	real;
	double	imag;
}			t_complx;

void		my_mlx_pixel_put(t_fractol *fractal, int x, int y, int color);
void		ft_draw(t_fractol *fractal);
void		my_mandelbrot_fractal(t_fractol *fractal);
void		my_julia_fractal(t_fractol *fractal);
void		start_draw(t_fractol *fractal);
void		fractal_initializer(t_fractol *fractal);
void		julia_checker(t_fractol *fractal, char **av);
void		fractol_types(void);
int			destroy_window(t_fractol *fractal);
int			key_press(int key, t_fractol *fractal);
int			mouse_press(int button, int x, int y, t_fractol *fractal);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atof(char *str);
int			check_num(char *str);
size_t		ft_strlen(const char *str);
void		set_initial_z(t_fractol *fractal, t_complx *z, int x, int y);
void		set_initial_c(t_fractol *fractal, t_complx *c);
void		iterate_julia(t_fractol *fractal, t_complx *z, t_complx *c);
void		julia_algo(t_fractol *fractal, int x, int y);

#endif