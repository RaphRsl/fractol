/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:21:08 by rroussel          #+#    #+#             */
/*   Updated: 2023/05/16 12:08:15 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "math.h"
# include "stdlib.h"
# include "unistd.h"

# define WIDTH 500
# define HEIGHT 500
# define MAX_ITER 60

enum
{
	MANDELBROT = 0,
	JULIA = 1,
	TRICORN = 2
};

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_image;

typedef struct s_fractal
{
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zx_new;
	int		color;
}			t_fractal;

typedef struct s_event
{
	double	zoom;
	double	x_move;
	double	y_move;
	int		x_mouse;
	int		y_mouse;
	int		base_color;
	double	julia_cx;
	double	julia_cy;
}			t_event;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*pixel;
	t_event	*event;
	int		type;
}			t_mlx;

void		draw_mandelbrot(t_image *pixel, t_event *event);
void		draw_julia(t_image *pixel, t_event *event);

int			first_pars(int argc, char **argv, t_mlx *fracto, t_event *event);

void		zoominout(t_mlx *fracto, double zoom);
int			update_win(t_mlx *fracto);
void		draw_pixel(int x, int y, int color, t_image *pixel);
void		colorize(t_fractal *info, t_image *pixel, t_event *event);

int			hook_key_handler(int keycode, t_mlx *fracto);
int			hook_mouse_handler(int button, int x, int y, t_mlx *fracto);
int			close_mlx(t_mlx *fracto);
#endif
