/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:31:45 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/04 13:01:17 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	clamp_channel(int value)
{
	if (value < 0)
		return (0);
	if (value > 255)
		return (255);
	return (value);
}

static unsigned int	interpolate_color(const int (*pal)[3], int seg, double t)
{
	int	r;
	int	g_c;
	int	b;

	r = pal[seg][0] + (int)((double)(pal[seg + 1][0] - pal[seg][0]) *t);
	g_c = pal[seg][1] + (int)((double)(pal[seg + 1][1] - pal[seg][1]) *t);
	b = pal[seg][2] + (int)((double)(pal[seg + 1][2] - pal[seg][2]) *t);
	r = clamp_channel(r);
	g_c = clamp_channel(g_c);
	b = clamp_channel(b);
	return ((unsigned int)((r << 16) | (g_c << 8) | b));
}

unsigned int	color_from_iter(int iter, int max_iter, t_fractal_type type)
{
	double		scaled;
	int			segment;
	const	int (*pal)[3];
	const int	mandelbrot[6][3] = {{9, 16, 51}, {30, 64, 175}, {14, 165, 233},
	{236, 72, 153}, {245, 158, 11}, {255, 248, 220}};
	const int	julia[6][3] = {{3, 7, 30}, {67, 97, 238}, {114, 9, 183}, {247,
		37, 133}, {255, 106, 0}, {255, 255, 255}};

	if (iter >= max_iter || max_iter <= 0)
		return (0x000000u);
	pal = mandelbrot;
	if (type == FRACTAL_JULIA)
		pal = julia;
	scaled = ((double)iter / (double)max_iter) * 5.0;
	segment = (int)scaled;
	if (segment > 4)
		segment = 4;
	scaled = scaled - (double)segment;
	return (interpolate_color(pal, segment, scaled));
}

unsigned int	app_color(t_app *app, int iter)
{
	if (app->palette && app->palette_size > 0)
	{
		if (iter < 0)
			iter = 0;
		if (iter >= app->palette_size)
			return (0x000000u);
		return (app->palette[iter]);
	}
	return (color_from_iter(iter, app->fractal.max_iter, app->fractal.type));
}
