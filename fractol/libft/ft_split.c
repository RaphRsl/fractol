/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:39:43 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/14 17:16:56 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(char const *str, char c)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			total++;
		while (str[i] != c && str[i])
		i++;
	}
	return (total);
}

static char	*word(char const *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	word = ft_calloc((i + 1), sizeof(char));
	if (!word)
	{
		free(word);
		return (NULL);
	}
	i = 0;
	while (str[i] != c && str[i])
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

static void	*free_all(char **string, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nb_words;
	char	**string;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	i = -1;
	string = ft_calloc((nb_words + 1), sizeof(char *));
	if (!string)
		return (NULL);
	while (++i < nb_words)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			string[i] = word(s, c);
		if (!(string[i]))
			return (free_all(string, i));
		while (*s && *s != c)
			s++;
	}
	string[i] = 0;
	return (string);
}
