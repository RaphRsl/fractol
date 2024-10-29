/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:14:01 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/28 17:31:09 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "stdio.h"

void	zoominout(t_mlx *fracto, double zoom)
{
	fracto->event->zoom *= zoom;
}

int	update_win(t_mlx *fracto)
{
	if (fracto->type == MANDELBROT)
		draw_mandelbrot(fracto->pixel, fracto->event);
	else if (fracto->type == JULIA)
		draw_julia(fracto->pixel, fracto->event);
	mlx_put_image_to_window(fracto->mlx_ptr, fracto->win_ptr,
		fracto->pixel->img, 0, 0);
	return (0);
}
