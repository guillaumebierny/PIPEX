/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:13:34 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/08 00:06:37 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*void_at_first(const char *s2, char *dest, int *i)
{
	dest = malloc(sizeof(char) * ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	while (s2[++(*i)])
		dest[(*i)] = s2[(*i)];
		dest[(*i)] = 0;
	return (dest);
}

void	copy_into_dest(const char *s1, const char *s2, char *dest, int i)
{
	int	j;

	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
	{
		dest[i] = s2[j];
		i++;
	}
	dest[i] = 0;
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;
	int		i;

	i = -1;
	dest = NULL;
	if (!s1 && !s2)
		return (NULL);
	i = -1;
	if (!s1 && s2)
		return (void_at_first(s2, dest, &i));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
		return (NULL);
	copy_into_dest(s1, s2, dest, i);
	return (dest);
}
