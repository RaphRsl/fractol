/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:22:18 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/28 10:24:59 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../includes/fractol.h"

void	move_by_mouse(t_mlx *fracto, double zoom);
void	draw_tricorn(t_image *pixel, t_event *event);

#endif