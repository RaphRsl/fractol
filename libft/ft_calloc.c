/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:35:35 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/14 15:58:55 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	unsigned char	*tab;
	size_t			mem;
	size_t			i;

	if (nb == 0 || size == 0)
		return (ft_calloc(1, 1));
	mem = nb * size;
	if (mem / nb != size)
		return (0);
	tab = malloc(mem);
	if (!tab)
		return (0);
	i = 0;
	while (i < mem)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
