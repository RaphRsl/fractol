/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:20:12 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/06 10:20:16 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keycode.h"

int	hook_key_handler(int keycode, t_mlx *fracto)
{
	if (keycode == KB_ESC)
		return (close_mlx(fracto));
	return (1);
}

int	hook_mouse_handler(int button, int x, int y, t_mlx *fracto)
{
	if (button == SCROLL_UP)
		return ((void)x, zoominout(fracto, 2), update_win(fracto));
	if (button == SCROLL_DOWN)
		return ((void)y, zoominout(fracto, 0.5), update_win(fracto));
	return (1);
}
