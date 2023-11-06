/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:36:52 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/14 15:16:09 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;

	if (!src && !dest)
		return (NULL);
	dest2 = (char *)dest;
	src2 = (char *)src;
	i = 0;
	if (dest2 > src2)
		while (n--)
			dest2[n] = src2[n];
	else
	{
		while (n--)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest2);
}
