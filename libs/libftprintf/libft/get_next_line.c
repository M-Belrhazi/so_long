/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:36:11 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/27 16:40:42 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fillline_continue(char *buffer, char *line, size_t i)
{
	size_t	k;

	k = 0;
	while (buffer[k] != '\n' && buffer[k])
	{
		line[i] = buffer[k];
		i++;
		k++;
	}
	if (buffer[k] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*fillline(char *buffer, char *line, int line_1)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = ft_strdup_2(line);
	if (!line_1)
		free(line);
	if (tmp == NULL)
		return (NULL);
	line = malloc(sizeof(char) * (ft_strlen_2(tmp) + ft_strlen_nl(buffer) + 1));
	if (line == NULL)
	{
		free(tmp);
		return (NULL);
	}
	while (tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (fillline_continue(buffer, line, i));
}

char	*analyse_and_return_buffer(char *buffer)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
	{
		tmp = ft_strdup_2(buffer + i + 1);
		if (tmp == NULL)
			return (NULL);
		i = 0;
		while (tmp[i])
		{
			buffer[i] = tmp[i];
			i++;
		}
		while (i < (size_t)BUFFER_SIZE)
		{
			buffer[i] = 0;
			i++;
		}
		free(tmp);
	}
	return (buffer);
}

char	*return_line(int fd, char *buffer, char *line, int line_1)
{
	int		ret;
	size_t	len;

	while (!newlinefound(buffer))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < BUFFER_SIZE)
			buffer[ret] = 0;
		len = ft_strlen_2(line) - (unsigned int)1;
		if ((int)len == -1)
			len = 0;
		if (ret == 0 && line[len] != '\n' && line[len])
			return (line);
		if (ret == -1 || ret == 0)
		{
			free(line);
			return (NULL);
		}
		line = fillline(buffer, line, line_1);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buff	buff;
	char			*line;
	int				a;

	if (!(buff.start))
	{
		buff.start = &a;
		if (BUFFER_SIZE > 0)
			buff.buffer[0] = 0;
	}
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!analyse_and_return_buffer(buff.buffer))
		return (NULL);
	line = fillline(buff.buffer, "", 1);
	if (line == NULL)
		return (NULL);
	return (return_line(fd, buff.buffer, line, 0));
}

/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY);
//	fd = 0;
	line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
*/
