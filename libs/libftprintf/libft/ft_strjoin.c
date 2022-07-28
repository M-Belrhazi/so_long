/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:15:46 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/27 16:54:18 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_fillsuperstr(char const *s1, char const *s2, char *superstr)
{
	int	i;
	int	k;

	i = 0;
	while (s1[i])
	{
		superstr[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		superstr[i] = s2[k];
		i++;
		k++;
	}
	free((char *)s1);
	return (superstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		count;
	char	*superstr;

	i = 0;
	while (s1[i])
		i++;
	count = i;
	i = 0;
	while (s2[i])
		i++;
	count += i + 1;
	superstr = malloc(sizeof(char) * count);
	if (superstr == NULL)
		return (free((char *)s1), NULL);
	superstr[count - 1] = '\0';
	return (ft_fillsuperstr(s1, s2, superstr));
}
