/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:21:02 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/06 10:21:03 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN= 5,
};

enum {
	KB_ESC = 0xFF1B,
	KB_UP = 0xFF52,
	KB_DOWN = 0xFF54,
	KB_RIGHT = 0xFF51,
	KB_LEFT = 0xFF53,
	KB_S = 0x73,
	KB_D = 0x64,
	KB_Z = 0x7A,
	KB_E = 0x65
};

#endif
