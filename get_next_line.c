/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:35:16 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/07 22:23:23 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*freefirst(char *first, char *sec)
{
	char	*tmp;

	tmp = ft_strjoin(first, sec);
	free(first);
	return (tmp);
}

char	*read_file(int fd, char **readed)
{
	char	*buffer;
	int		readb;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readb = 1;
	while (readb > 0)
	{
		readb = read(fd, buffer, BUFFER_SIZE);
		if (readb == -1)
		{
			free(buffer);
			free(*readed);
			*readed = NULL;
			return (NULL);
		}
		buffer[readb] = 0;
		*readed = freefirst(*readed, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (*readed);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*remove_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, &buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = remove_line(buffer);
	return (line);
}
