/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:21:57 by rroussel          #+#    #+#             */
/*   Updated: 2023/05/16 11:18:22 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "stdio.h"

int	display_help(char *error)
{
	if (error)
		write(1, "You need to add a valid option\n", 31);
	write(1, "How to use fract-ol: ./fract-ol FRACTAL_TYPE [cx] [cy]\n", 55);
	write(1, "FRACTAL_TYPE: mandelbrot, julia\n", 32);
	write(1, "cx/cy: have to be floats or ints\n", 33);
	return (F_OK);
}

int	first_pars(int argc, char **argv, t_mlx *fracto, t_event *event)
{
	if (argc < 1)
		return (display_help(NULL));
	if (ft_strncmp(argv[0], "mandelbrot", 11) == 0)
		fracto->type = MANDELBROT;
	else if (ft_strncmp(argv[0], "julia", 6) == 0)
		fracto->type = JULIA;
	else if (ft_strncmp(argv[0], "tricorn", 8) == 0)
		fracto->type = TRICORN;
	else
		return (display_help(argv[0]));
	event->julia_cx = -0.7;
	event->julia_cy = 0.27015;
	if (argc >= 2)
	{
		if (!ft_isdouble(argv[1]))
			return (display_help(argv[1]));
		event->julia_cx = ft_atof(argv[1]);
	}
	if (argc >= 3)
	{
		if (!ft_isdouble(argv[2]))
			return (display_help(argv[2]));
		event->julia_cy = ft_atof(argv[2]);
	}
	return (1);
}
