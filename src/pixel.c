/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 12:01:19 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/04 13:08:10 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	write_pixel_bytes(char *dst, unsigned int color, int bpp,
		int endian)
{
	int	bytes;
	int	i;

	bytes = bpp / 8;
	i = 0;
	while (i < bytes)
	{
		if (endian == 0)
			dst[i] = (unsigned char)((color >> (8 * i)) & 0xFF);
		else
			dst[i] = (unsigned char)((color >> (8 * (bytes - 1 - i))) & 0xFF);
		++i;
	}
}

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (!img || !img->addr || x < 0 || y < 0)
		return ;
	if (img->bpp <= 0 || (img->bpp % 8) != 0)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	write_pixel_bytes(dst, color, img->bpp, img->endian);
}

void	safe_put_pixel(t_app *app, int x, int y, unsigned int color)
{
	char	*dst;

	if (!app || !app->mlx)
		return ;
	if (app->img.addr && app->img.bpp > 0 && (app->img.bpp % 8) == 0)
	{
		dst = app->img.addr + (y * app->img.line_len + x * (app->img.bpp / 8));
		write_pixel_bytes(dst, color, app->img.bpp, app->img.endian);
	}
	else
		mlx_pixel_put(app->mlx, app->win, x, y, color);
}
