/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:43:34 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/11 13:46:55 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	res = 1;
	i = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	else if (n != 0)
	{
		while (s1[i] && n > 0)
		{
			if (s1[i] == s2[0] && ft_strlen((char *)s2) <= n)
			{
				res = ft_strncmp(s1 + i, s2, ft_strlen((char *)s2));
				if (res == 0)
					return ((char *)(s1 + i));
			}
			i++;
			n--;
		}
	}
	return (0);
}
