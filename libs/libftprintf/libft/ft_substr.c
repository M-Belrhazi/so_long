/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:19:37 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/27 15:06:30 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	i = 0;
	if (start > slen)
	{
		return (ft_strdup(""));
	}
	if (start + len < slen)
		slen = start + len;
	str = malloc(sizeof(char) * (slen - start + 1));
	if (str == NULL)
		return (str);
	while (i < (slen - start) && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
