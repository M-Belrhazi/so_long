/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:32:32 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/12 17:40:46 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*erase_nl(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0)
	{
		if (str[len - 1] == '\n')
			str[len - 1] = '\0';
		str = ft_strdup(str);
		if (!str)
			return (NULL);
	}
	return (str);
}

size_t	ft_strlen_no_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int	nl_ol_map(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
