/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:23:12 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/18 16:42:42 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	introducing an array of function pointers for writing errors respectively
	to the return value
*/

int	fill_map(char ***map, char *ol_map)
{
	ol_map = ft_strtrim(ol_map, "\n");
	if (!ol_map)
		return (ret_write(1), 1);
	if (nl_ol_map(ol_map))
		return (free(ol_map), ret_write(4), 4);
	*map = ft_split(ol_map, '\n');
	if (!(*map))
		return (ret_write(1), 1);
	if (!walls_map(*map) || invalid_char_map(*map)
		|| !exit_map(*map) || !player_map(*map) || !col_map(*map))
		return (free(ol_map), free_map(*map), 1);
	free(ol_map);
	return (0);
}

char	*find_first_line(char *line, int fd)
{
	while (line != NULL && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	ft_free(char *line, char *ol_map)
{
	free(line);
	free(ol_map);
}

int	fill_one_line_map(int fd, char ***map)
{
	char	*line;
	char	*ol_map;
	size_t	og_len;
	size_t	len;

	ol_map = ft_strdup("");
	if (!ol_map)
		return (ret_write(1), 1);
	line = get_next_line(fd);
	line = find_first_line(line, fd);
	if (line == NULL || line[0] == '\0')
		return (ft_free(line, ol_map), ret_write(2), 2);
	og_len = ft_strlen_no_nl(line);
	while (line)
	{
		len = ft_strlen_no_nl(line);
		if (len != og_len && len != 0)
			return (ft_free(line, ol_map), ret_write(3), 3);
		ol_map = ft_strjoin(ol_map, line);
		if (!ol_map)
			return (free(line), ret_write(1), 1);
		free(line);
		line = get_next_line(fd);
	}
	return (fill_map(map, ol_map));
}
