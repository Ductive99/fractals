/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:12:50 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/04 13:06:35 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_app	app;

	app_defaults(&app);
	if (!app_init(&app, argc, argv))
		return (EXIT_FAILURE);
	mlx_loop(app.mlx);
	app_destroy(&app);
	return (EXIT_SUCCESS);
}
