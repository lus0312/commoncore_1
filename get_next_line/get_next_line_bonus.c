/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:52:54 by eulee             #+#    #+#             */
/*   Updated: 2024/11/27 16:40:28 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_backup(int fd, char *backup[fd])
{
	char	*temp;
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen(backup[fd]);
	while (backup[fd][index] && backup[fd][index] != '\n')
		index++;
	if (backup[fd][index] == '\n')
		temp = ft_substr(backup[fd], index + 1, len - index - 1);
	else
		temp = NULL;
	if (backup[fd])
	{
		free(backup[fd]);
		backup[fd] = NULL;
	}
	return (temp);
}

char	*extract_line(int fd, char *backup[fd])
{
	char	*line;
	size_t	index;

	index = 0;
	while (backup[fd][index] && backup[fd][index] != '\n')
		index++;
	if (backup[fd][index] == '\n')
		line = ft_substr(backup[fd], 0, index + 1);
	else
		line = ft_substr(backup[fd], 0, index);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_line(int fd, char *buffer, char *backup[fd])
{
	ssize_t	byte_read;

	byte_read = 0;
	while (fd >= 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			if (backup[fd] != NULL)
				free(backup[fd]);
			return (NULL);
		}
		else if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		backup[fd] = gnl_strjoin(backup[fd], buffer);
		if (!backup)
			return (NULL);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	if (byte_read == 0 && !backup)
		return (NULL);
	return (backup[fd]);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	backup[fd] = read_line(fd, buffer, backup);
	free (buffer);
	if (!backup[fd])
		return (NULL);
	if (backup[fd][0] == '\0')
	{
		free (backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	line = extract_line(fd, backup);
	backup[fd] = update_backup(fd, backup);
	return (line);
}
