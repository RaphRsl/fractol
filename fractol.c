/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:19:26 by rroussel          #+#    #+#             */
/*   Updated: 2023/05/16 09:55:02 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"
#include "includes/keycode.h"

int	close_mlx(t_mlx *fractol)
{
	mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	mlx_destroy_image(fractol->mlx_ptr, fractol->pixel->img);
	mlx_destroy_display(fractol->mlx_ptr);
	free(fractol->mlx_ptr);
	exit(EXIT_SUCCESS);
}

t_mlx	*initialization(t_mlx *fractol, t_event *event, t_image *pixel)
{
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
		return (NULL);
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT,
			"Fract-ol");
	pixel->img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bpp, &pixel->len,
			&pixel->endian);
	fractol->pixel = pixel;
	event->zoom = 1;
	event->x_move = 0;
	event->y_move = 0;
	event->x_mouse = WIDTH / 2;
	event->y_mouse = HEIGHT / 2;
	event->base_color = 0x000000ff;
	fractol->event = event;
	return (fractol->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	fractol;
	t_image	pixel;
	t_event	event;

	if (!first_pars(argc - 1, argv + 1, &fractol, &event))
		return (0);
	if (!initialization(&fractol, &event, &pixel))
		return (0);
	update_win(&fractol);
	mlx_hook(fractol.win_ptr, ON_DESTROY, 1L << 17, close_mlx, &fractol);
	mlx_hook(fractol.win_ptr, ON_KEYDOWN, 1L << 0, hook_key_handler, &fractol);
	mlx_mouse_hook(fractol.win_ptr, hook_mouse_handler, &fractol);
	mlx_loop(fractol.mlx_ptr);
}
