/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:22:26 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/28 17:02:24 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycode.h"
#include "fractol_bonus.h"
#include "stdio.h"

t_mlx	*initialization(t_mlx *fracto, t_event *event, t_image *pixel)
{
	fracto->mlx_ptr = mlx_init();
	if (!fracto->mlx_ptr)
		return (NULL);
	fracto->win_ptr = mlx_new_window(fracto->mlx_ptr, WIDTH, HEIGHT,
			"Fract-ol");
	pixel->img = mlx_new_image(fracto->mlx_ptr, WIDTH, HEIGHT);
	pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bpp, &pixel->len,
			&pixel->endian);
	fracto->pixel = pixel;
	event->zoom = 1;
	event->x_move = 0;
	event->y_move = 0;
	event->x_mouse = WIDTH / 2;
	event->y_mouse = HEIGHT / 2;
	event->base_color = 0x000000ff;
	fracto->event = event;
	return (fracto->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	fracto;
	t_image	pixel;
	t_event	event;

	if (!first_pars(argc - 1, argv + 1, &fracto, &event))
		return (EXIT_SUCCESS);
	if (!initialization(&fracto, &event, &pixel))
		return (EXIT_SUCCESS);
	update_win(&fracto);
	mlx_hook(fracto.win_ptr, ON_DESTROY, 1L << 17, close_mlx, &fracto);
	mlx_hook(fracto.win_ptr, ON_KEYDOWN, 1L << 0, hook_key_handler, &fracto);
	mlx_mouse_hook(fracto.win_ptr, hook_mouse_handler, &fracto);
	mlx_loop(fracto.mlx_ptr);
}
