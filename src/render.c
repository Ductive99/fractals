/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:32:42 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/03 17:39:34 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_frame(t_app *app)
{
	if (!app || !app->mlx || !app->win || !app->img.addr)
		return ;
	if (app->fractal.type == FRACTAL_MANDELBROT)
		render_mandelbrot(app);
	else if (app->fractal.type == FRACTAL_JULIA)
		render_julia(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img.ptr, 0, 0);
}
