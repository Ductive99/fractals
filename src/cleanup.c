/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:31:34 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/03 17:38:36 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	app_destroy(t_app *app)
{
	if (!app)
		return ;
	if (app->mlx && app->img.ptr)
	{
		mlx_destroy_image(app->mlx, app->img.ptr);
		app->img.ptr = NULL;
		app->img.addr = NULL;
	}
	if (app->palette)
	{
		free(app->palette);
		app->palette = NULL;
		app->palette_size = 0;
	}
	if (app->mlx && app->win)
	{
		mlx_destroy_window(app->mlx, app->win);
		app->win = NULL;
	}
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		app->mlx = NULL;
	}
}

void	app_exit(t_app *app, int status, const char *message)
{
	app_destroy(app);
	if (message)
		ft_putstr_fd((char *)message, 2);
	exit(status);
}
