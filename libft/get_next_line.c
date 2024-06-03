/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:25:07 by dtoszek           #+#    #+#             */
/*   Updated: 2024/05/25 13:25:42 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <fcntl.h>

char	*ft_free(char *res, char *buf)
{
	char	*temp;

	temp = ft_strjoin(res, buf);
	free(res);
	return (temp);
}

char	*read_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
	{
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*read_next(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	j = 0;
	i++;
	while (buffer[i])
	{
		temp[j++] = buffer[i++];
	}
	free (buffer);
	return (temp);
}

char	*read_next_line(int fd, char *result)
{
	int		bytes_read;
	char	*buffer;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = 0;
		result = ft_free(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read == -1)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	char			*lin;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_next_line(fd, buf);
	if (!buf)
		return (NULL);
	lin = read_line(buf);
	buf = read_next(buf);
	return (lin);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.c", O_RDONLY);
	i = 0;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
*/
