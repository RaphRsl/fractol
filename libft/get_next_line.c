/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:51:04 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/06 10:51:07 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_next_line(char *str)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	next_line = (char *)malloc((gnl_ft_strlen(str) - i + sizeof('\0'))
			* sizeof(char));
	if (!next_line)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
		next_line[j++] = str[i++];
	next_line[j] = '\0';
	free(str);
	return (next_line);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc((i + sizeof('\n') + sizeof('\0')) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		line[j++] = str[i++];
	if (str[i] == '\n')
		line[j++] = str[i++];
	line[j] = '\0';
	return (line);
}

char	*read_to_eol(int fd, char *str)
{
	char	*buff;
	int		opened;

	buff = (char *)malloc((BUFFER_SIZE + sizeof('\0')) * sizeof(char));
	if (!buff)
		return (NULL);
	opened = 1;
	while (!gnl_ft_strchr(str, '\n') && opened != 0)
	{
		opened = read(fd, buff, BUFFER_SIZE);
		if (opened == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[opened] = '\0';
		str = gnl_ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_to_eol(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = to_next_line(str[fd]);
	return (line);
}
