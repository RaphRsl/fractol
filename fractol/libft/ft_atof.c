/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:29:51 by rroussel          #+#    #+#             */
/*   Updated: 2023/05/17 17:56:35 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *nptr)
{
	double	result;
	double	deci;
	int		neg;
	int		i;
	int		deci_i;

	i = 0;
	if (nptr[i] == '-' && ++i)
		neg = -1;
	else
		neg = 1;
	result = ft_atoi(nptr);
	while (nptr[i] && nptr[i] != '.')
		i++;
	if (!nptr[i])
		return (result);
	deci = ft_atol(&nptr[++i]);
	deci_i = -1;
	while (nptr[++deci_i + i])
		deci /= 10;
	return ((result + deci) * neg);
}
