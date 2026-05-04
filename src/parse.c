/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 01:43:18 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/04 13:07:11 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	str_eq(const char *a, const char *b)
{
	if (!a || !b)
		return (0);
	return (ft_strncmp(a, b, ft_strlen(a) + 1) == 0);
}

static int	set_mandelbrot(t_app *app)
{
	app->fractal.type = FRACTAL_MANDELBROT;
	app->fractal.max_iter = 100;
	app->view.center_x = -0.5;
	app->view.center_y = 0.0;
	app->view.zoom = 1.0;
	return (1);
}

static int	set_julia(t_app *app, const char *re, const char *im)
{
	if (!ft_atod(re, &app->fractal.julia_c_re))
		return (0);
	if (!ft_atod(im, &app->fractal.julia_c_im))
		return (0);
	app->fractal.type = FRACTAL_JULIA;
	app->fractal.max_iter = 100;
	app->view.center_x = 0.0;
	app->view.center_y = 0.0;
	app->view.zoom = 1.0;
	return (1);
}

void	print_usage(void)
{
	ft_putendl_fd("Usage:", 1);
	ft_putendl_fd("  ./fractol mandelbrot", 1);
	ft_putendl_fd("  ./fractol julia <real> <imag>", 1);
}

int	parse_args(t_app *app, int argc, char **argv)
{
	if (argc == 2 && str_eq(argv[1], "mandelbrot"))
		return (set_mandelbrot(app));
	if (argc == 4 && str_eq(argv[1], "julia"))
		return (set_julia(app, argv[2], argv[3]));
	print_usage();
	return (0);
}
