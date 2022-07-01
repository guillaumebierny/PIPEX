/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:55:17 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/11 18:51:01 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, const char *set)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	char	*dest;
	size_t	ind_pref;
	size_t	ind_suff;

	ind_pref = 0;
	ind_suff = 0;
	i = -1;
	if (!set)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	while (is_in(s1[++i], set))
		ind_pref++;
	i = ft_strlen((char *)s1);
	if (ind_pref != ft_strlen((char *)s1))
	{
		while (is_in(s1 [--i], set))
			ind_suff++;
	}
	dest = ft_substr(s1, ind_pref, ft_strlen((char *)s1) - ind_suff - ind_pref);
	return (dest);
}
