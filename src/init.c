/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:31:19 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/04 12:58:09 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	app_defaults(t_app *app)
{
	app->width = WIN_WIDTH;
	app->height = WIN_HEIGHT;
	app->running = 1;
	app->view.center_x = -0.5;
	app->view.center_y = 0.0;
	app->view.zoom = 1.0;
	app->fractal.type = FRACTAL_INVALID;
	app->fractal.max_iter = 100;
	app->fractal.julia_c_re = 0.0;
	app->fractal.julia_c_im = 0.0;
	app->mlx = NULL;
	app->win = NULL;
	app->img.ptr = NULL;
	app->img.addr = NULL;
	app->palette = NULL;
	app->palette_size = 0;
}

static int	init_window_and_image(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (0);
	app->win = mlx_new_window(app->mlx, app->width, app->height, WIN_TITLE);
	if (!app->win)
		return (0);
	app->img.ptr = mlx_new_image(app->mlx, app->width, app->height);
	if (!app->img.ptr)
		return (0);
	app->img.addr = mlx_get_data_addr(app->img.ptr, &app->img.bpp,
			&app->img.line_len, &app->img.endian);
	if (!app->img.addr)
		return (0);
	app->img.direct = (app->img.bpp == 32 && app->img.endian == 0);
	return (1);
}

static int	init_with_hooks_and_palette(t_app *app)
{
	int	i;

	mlx_hook(app->win, 2, 1L << 0, (void *)handle_keypress, app);
	mlx_hook(app->win, 4, 1L << 2, (void *)handle_mouse, app);
	mlx_hook(app->win, 17, 1L << 0, (void *)handle_close, app);
	mlx_hook(app->win, 12, 1L << 15, (void *)handle_expose, app);
	if (app->fractal.max_iter > 0)
	{
		app->palette_size = app->fractal.max_iter + 1;
		app->palette = (unsigned int *)ft_calloc(app->palette_size,
				sizeof(unsigned int));
		if (!app->palette)
			return (0);
		i = 0;
		while (i <= app->fractal.max_iter)
		{
			app->palette[i] = color_from_iter(i, app->fractal.max_iter,
					app->fractal.type);
			i++;
		}
	}
	return (1);
}

int	app_init(t_app *app, int argc, char **argv)
{
	if (!app)
		return (0);
	if (!parse_args(app, argc, argv))
		return (0);
	if (!init_window_and_image(app))
		return (0);
	if (!init_with_hooks_and_palette(app))
		return (0);
	return (1);
}
