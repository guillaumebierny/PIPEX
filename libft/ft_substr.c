/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:18:53 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/21 15:02:39 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return ((char *)ft_calloc(1, sizeof(char)));
	while ((s + start)[i])
		i++;
	if (i < len)
		len = i;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (len--)
	{
		dest[i] = (s + start)[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
