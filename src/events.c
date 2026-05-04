/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:31:53 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/04 12:58:09 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == KEY_ESC)
		app_exit(app, EXIT_SUCCESS, NULL);
	return (0);
}

int	handle_mouse(int button, int x, int y, void *param)
{
	t_app	*app;
	double	scale;
	double	cursor_re;
	double	cursor_im;

	app = (t_app *)param;
	if (button != MOUSE_WHEEL_UP && button != MOUSE_WHEEL_DOWN)
		return (0);
	scale = 4.0 / ((double)app->height * app->view.zoom);
	cursor_re = ((double)x - (double)app->width / 2.0) * scale
		+ app->view.center_x;
	cursor_im = ((double)y - (double)app->height / 2.0) * scale
		+ app->view.center_y;
	if (button == MOUSE_WHEEL_UP)
		app->view.zoom *= ZOOM_IN_FACTOR;
	else
		app->view.zoom *= ZOOM_OUT_FACTOR;
	if (app->view.zoom < 0.05)
		app->view.zoom = 0.05;
	scale = 4.0 / ((double)app->height * app->view.zoom);
	app->view.center_x = cursor_re - ((double)x - (double)app->width / 2.0)
		* scale;
	app->view.center_y = cursor_im - ((double)y - (double)app->height / 2.0)
		* scale;
	return (render_frame(app), 0);
}

int	handle_close(void *param)
{
	app_exit((t_app *)param, EXIT_SUCCESS, NULL);
	return (0);
}

int	handle_expose(void *param)
{
	render_frame((t_app *)param);
	return (0);
}
