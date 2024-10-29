/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:50:41 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/06 10:50:45 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)s + gnl_ft_strlen(s));
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	len;
	int		i;
	int		j;

	if ((!s1 || !s1[0]) && !s2[0])
	{
		free(s1);
		return (NULL);
	}
	len = gnl_ft_strlen(s1) + gnl_ft_strlen(s2);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (malloc(0));
	i = 0;
	j = 0;
	while (s1 && s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		new[j++] = s2[i++];
	new[len] = '\0';
	free(s1);
	return (new);
}

size_t	gnl_ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
