/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:22:11 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/28 10:20:27 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "fractol_bonus.h"
#include "../includes/keycode.h"

int	close_mlx(t_mlx *fracto)
{
	mlx_destroy_window(fracto->mlx_ptr, fracto->win_ptr);
	mlx_destroy_image(fracto->mlx_ptr, fracto->pixel->img);
	mlx_destroy_display(fracto->mlx_ptr);
	free(fracto->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	hook_key_handler(int keycode, t_mlx *fracto)
{
	if (keycode == KB_ESC)
		return (close_mlx(fracto));
	if (keycode == KB_Z)
		return (fracto->event->base_color += 0x0000ff00, update_win(fracto));
	if (keycode == KB_E)
		return (fracto->event->base_color -= 0x0000ff00, update_win(fracto));
	if (keycode == KB_DOWN)
		return (fracto->event->y_move += (0.1 / fracto->event->zoom),
			update_win(fracto));
	if (keycode == KB_UP)
		return (fracto->event->y_move -= (0.1 / fracto->event->zoom),
			update_win(fracto));
	if (keycode == KB_LEFT)
		return (fracto->event->x_move += (0.1 / fracto->event->zoom),
			update_win(fracto));
	if (keycode == KB_RIGHT)
		return (fracto->event->x_move -= (0.1 / fracto->event->zoom),
			update_win(fracto));
	return (1);
}

int	hook_mouse_handler(int button, int x, int y, t_mlx *fracto)
{
	if (button == SCROLL_UP)
		return (move_by_mouse(fracto, 2), update_win(fracto));
	if (button == SCROLL_DOWN)
		return (move_by_mouse(fracto, 0.5), update_win(fracto));
	return ((void)x, (void)y, 1);
}
