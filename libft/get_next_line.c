/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:34:48 by odib              #+#    #+#             */
/*   Updated: 2024/06/29 16:00:25 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*parse(int fd, char *saved, char *buffer)
{
	char	*current;
	int		b_read;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(saved);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!saved)
			saved = ft_strdup("");
		current = saved;
		saved = ft_strjoin(current, buffer);
		free(current);
		if (ft_strchr(saved, '\n'))
			break ;
	}
	return (saved);
}

char	*set_new_line(char *line)
{
	int		i;
	char	*saved;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		i++;
	}
	if (line[i] == '\0')
		return (NULL);
	saved = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*saved == '\0')
	{
		free(saved);
		saved = NULL;
	}
	line[i + 1] = '\0';
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*saved;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(saved);
		return (NULL);
	}
	line = parse(fd, saved, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	saved = set_new_line(line);
	return (line);
}
