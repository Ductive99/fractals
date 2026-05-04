/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 01:35:08 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/04 13:31:23 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define WIN_TITLE "fractol"
# define KEY_ESC 65307
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ZOOM_IN_FACTOR 1.2
# define ZOOM_OUT_FACTOR 0.8333333333333334

typedef enum e_fractal_type
{
	FRACTAL_INVALID = -1,
	FRACTAL_MANDELBROT = 0,
	FRACTAL_JULIA = 1
}					t_fractal_type;

typedef struct s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				direct;
}					t_img;

typedef struct s_view
{
	double			center_x;
	double			center_y;
	double			zoom;
}					t_view;

typedef struct s_fractal
{
	double			julia_c_re;
	double			julia_c_im;
	int				max_iter;
	t_fractal_type	type;
}					t_fractal;

typedef struct s_app
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_view			view;
	t_fractal		fractal;
	int				width;
	int				height;
	int				running;
	unsigned int	*palette;
	int				palette_size;
}					t_app;

void				app_defaults(t_app *app);
int					app_init(t_app *app, int argc, char **argv);
void				app_destroy(t_app *app);
void				app_exit(t_app *app, int status, const char *message);
int					parse_args(t_app *app, int argc, char **argv);
void				print_usage(void);
void				render_frame(t_app *app);
void				render_mandelbrot(t_app *app);
void				render_julia(t_app *app);
unsigned int		color_from_iter(int iter, int max_iter,
						t_fractal_type type);
unsigned int		app_color(t_app *app, int iter);
void				put_pixel(t_img *img, int x, int y, unsigned int color);
void				safe_put_pixel(t_app *app, int x, int y,
						unsigned int color);
int					handle_keypress(int keycode, void *param);
int					handle_mouse(int button, int x, int y, void *param);
int					handle_close(void *param);
int					handle_expose(void *param);
int					ft_atod(const char *s, double *out);

#endif
