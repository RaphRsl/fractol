/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:20:28 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/28 10:26:33 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "stdio.h"

void	draw_mandelbrot(t_image *pixel, t_event *event)
{
	t_fractal	info;

	info.x = -1;
	while (++info.x < WIDTH)
	{
		info.y = -1;
		while (++info.y < HEIGHT)
		{
			info.cx = (info.x - WIDTH / 2) * 4.0 / (WIDTH * event->zoom)
				+ (event->x_move);
			info.cy = (info.y - HEIGHT / 2) * 4.0 / (HEIGHT * event->zoom)
				+ (event->y_move);
			info.zx = 0.0;
			info.zy = 0.0;
			info.color = -1;
			while (info.zx * info.zx + info.zy * info.zy < 4
				&& ++info.color < MAX_ITER)
			{
				info.zx_new = info.zx * info.zx - info.zy * info.zy + info.cx;
				info.zy = 2 * info.zx * info.zy + info.cy;
				info.zx = info.zx_new;
			}
			colorize(&info, pixel, event);
		}
	}
}
