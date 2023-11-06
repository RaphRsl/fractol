/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:44:11 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/14 14:01:34 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( const char *str, int c )
{
	int	i;

	i = ft_strlen(str);
	while (*str != 0 && i >= 0)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)str + i);
		i--;
	}
	if (c == 0)
		return ((char *)str);
	return (NULL);
}
