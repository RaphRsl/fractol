/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:21:11 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/28 10:22:33 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "../includes/keycode.h"

void	zoominout(t_mlx *fracto, double zoom)
{
	fracto->event->zoom *= zoom;
}

void	move_by_mouse(t_mlx *fracto, double zoom)
{
	mlx_mouse_get_pos(fracto->mlx_ptr, fracto->win_ptr, &fracto->event->x_mouse,
		&fracto->event->y_mouse);
	if (zoom > 1)
	{
		fracto->event->x_move += (fracto->event->x_mouse - WIDTH / 2 - 0.5)
			* (4.0 / (WIDTH * fracto->event->zoom * zoom));
		fracto->event->y_move += (fracto->event->y_mouse - HEIGHT / 2 - 0.5)
			* (4.0 / (HEIGHT * fracto->event->zoom * zoom));
	}
	else
	{
		fracto->event->x_move -= (fracto->event->x_mouse - WIDTH / 2 - 0.5)
			* (4.0 / (WIDTH * fracto->event->zoom));
		fracto->event->y_move -= (fracto->event->y_mouse - HEIGHT / 2 - 0.5)
			* (4.0 / (HEIGHT * fracto->event->zoom));
	}
	zoominout(fracto, zoom);
}

int	update_win(t_mlx *fracto)
{
	if (fracto->type == MANDELBROT)
		draw_mandelbrot(fracto->pixel, fracto->event);
	else if (fracto->type == JULIA)
		draw_julia(fracto->pixel, fracto->event);
	else if (fracto->type == TRICORN)
		draw_tricorn(fracto->pixel, fracto->event);
	mlx_put_image_to_window(fracto->mlx_ptr, fracto->win_ptr,
		fracto->pixel->img, 0, 0);
	return (0);
}
