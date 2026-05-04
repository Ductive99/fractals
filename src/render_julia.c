/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:32:27 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/04 12:46:00 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	julia_iter(double z_re, double z_im, t_app *app)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (iter < app->fractal.max_iter && z_re * z_re + z_im * z_im <= 4.0)
	{
		tmp = z_re * z_re - z_im * z_im + app->fractal.julia_c_re;
		z_im = 2.0 * z_re * z_im + app->fractal.julia_c_im;
		z_re = tmp;
		++iter;
	}
	return (iter);
}

static void	render_line_direct(t_app *app, int y, double start_re,
		double scale)
{
	unsigned int	*p;
	double			re;
	int				x;
	double			im;

	p = (unsigned int *)(app->img.addr + (y * app->img.line_len));
	re = start_re;
	im = app->view.center_y - ((double)app->height * 0.5 * scale)
		+ ((double)y * scale);
	x = 0;
	while (x < app->width)
	{
		*p = app_color(app, julia_iter(re, im, app));
		++p;
		re += scale;
		++x;
	}
}

static void	render_line_fallback(t_app *app, int y, double start_re,
		double scale)
{
	double			re;
	int				x;
	double			im;

	re = start_re;
	im = app->view.center_y - ((double)app->height * 0.5 * scale)
		+ ((double)y * scale);
	x = 0;
	while (x < app->width)
	{
		safe_put_pixel(app, x, y,
			app_color(app, julia_iter(re, im, app)));
		re += scale;
		++x;
	}
}

void	render_julia(t_app *app)
{
	double			scale;
	double			start_re;
	int				y;

	scale = 4.0 / ((double)min_int(app->width, app->height) * app->view.zoom);
	start_re = app->view.center_x - ((double)app->width * 0.5 * scale);
	y = 0;
	while (y < app->height)
	{
		if (app->img.direct)
			render_line_direct(app, y, start_re, scale);
		else
			render_line_fallback(app, y, start_re, scale);
		++y;
	}
}
