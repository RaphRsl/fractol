/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:33:18 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/06 10:33:20 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdouble(char *str)
{
	if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	else if (*str == '.' && ft_isdigit(*(++str)))
	{
		str++;
		while (*str && ft_isdigit(*str))
			str++;
		if (*str == '\0')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
