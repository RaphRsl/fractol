/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:20:39 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/28 10:26:17 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_pixel(int x, int y, int color, t_image *pixel)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->len + x * (pixel->bpp / 8));
	*(unsigned int *)dst = color;
}

int	argb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	colorize(t_fractal *info, t_image *pixel, t_event *event)
{
	int	color;

	color = argb(0,
			(event->base_color * info->color) * 255 / MAX_ITER,
			(event->base_color * info->color) * 255 / MAX_ITER,
			(event->base_color * info->color) * 255 / MAX_ITER);
	if (info->color == MAX_ITER)
		draw_pixel(info->x, info->y, 0x000000, pixel);
	else
		draw_pixel(info->x, info->y, event->base_color + color, pixel);
}
