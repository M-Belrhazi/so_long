/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:20:14 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/18 15:26:14 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	***** FIND_ERROR *****

	find_error's aim is to find the potential errors in the argument of main.
	It includes :
	- file doesn't have the .ber extension
	- file is hidden
	The file can have multiple extensions, or be located in a hidden repository.
*/

#include "so_long.h"

int	find_error(char *str)
{
	size_t	len;
	size_t	len_ber;
	size_t	i;
	char	*ber;

	len = ft_strlen(str);
	len_ber = ft_strlen(".ber");
	ber = ".ber";
	i = 0;
	while (i < len_ber)
	{
		if (str[len - 1 - i] != ber[len_ber - 1 - i])
		{
			return (write(2, ".ber file requested\n", 20), 1);
		}
		i++;
	}
	while ((int)len - 1 - (int)i > -1 && str[len - 1 - i] != '/')
		i++;
	if (str[len - i] == '.')
	{
		write(2, "NO HIDDEN FILES\n", 16);
		return (1);
	}
	return (0);
}

int	parse(char *file, char ***map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Invalid file or path\n", 21);
		return (1);
	}
	if (fill_one_line_map(fd, map))
	{
		return (close(fd), 1);
	}
	close(fd);
	return (0);
}
