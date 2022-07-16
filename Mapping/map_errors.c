/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:25:15 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/12 17:40:41 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	walls_map(char **map)
{
	size_t	i;
	size_t	j;
	size_t	line_size;

	line_size = ft_strlen(map[0]);
	i = 0;
	if (!map[0])
		return (write(2, "Error\nYou have no map\n", 22), 0);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][line_size - 1] != '1')
			return (write(2, "Error\ncheck your walls\n", 23), 0);
		i++;
	}
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (write(2, "Error\ncheck your walls\n", 23), 0);
		j++;
	}
	return (1);
}

int	invalid_char_map(char **map)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != 'E' && c != 'C' && c != '0' && c != 'P' && c != '1')
				return (write(2, "Error\ninvalid character in map\n", 31), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	exit_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (write(2, "Error\nNo exit\n", 14), 0);
}

int	col_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (write(2, "Error\nNo collectible\n", 21), 0);
}

int	player_map(char **map)
{
	size_t	i;
	size_t	j;
	int		found;

	found = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				found++;
			j++;
		}
		i++;
	}
	if (found == 1)
		return (1);
	if (found > 1)
		return (write(2, "Error\nmore than one player\n", 27), 0);
	return (write(2, "Error\nNo player\n", 16), 0);
}
