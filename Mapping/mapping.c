/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:23:12 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/12 21:44:21 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	fill_map(char ***map, char *ol_map)
{
	ol_map = ft_strtrim(ol_map, "\n");
	if (!ol_map)
		return (write(2, "malloc error\n", 13), 1);
	if (nl_ol_map(ol_map))
		return (free(ol_map), write(2, "Error\nmap cut\n", 14), 3);
	*map = ft_split(ol_map, '\n');
	if (!(*map))
		return (write(2, "malloc error\n", 13), 1);
	if (!walls_map(*map) || invalid_char_map(*map)
		|| !exit_map(*map) || !player_map(*map) || !col_map(*map))
		return (free(ol_map), free_map(*map), 4);
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

int	fill_one_line_map(int fd, char ***map)
{
	char	*line;
	char	*ol_map;
	size_t	len;

	ol_map = ft_strdup("");
	if (!ol_map)
		return (write(2, "malloc error\n", 13), 1);
	line = get_next_line(fd);
	line = find_first_line(line, fd);
	if (line == NULL || line[0] == '\0')
		return (free(line), free(ol_map), write(2, "Error\nFile empty\n", 17), 5);
	if (line != NULL)
		len = ft_strlen_no_nl(line);
	while (line)
	{
		if (ft_strlen_no_nl(line) != len && ft_strlen_no_nl(line) != 0)
			return (free(line), free(ol_map),
				write(2, "Error\nmap not a rectangle\n", 26), 2);
		ol_map = ft_strjoin(ol_map, line);
		if (!ol_map)
			return (free(line), write(2, "malloc error\n", 13), 1);
		free(line);
		line = get_next_line(fd);
	}
	return (fill_map(map, ol_map));
}
