/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:45:47 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/11 13:24:40 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	i = -1;
	if (ft_strlen(src) == 1)
		dest[0] = 0;
	if (size != 0)
	{
		while (src[++i] && (size--) - 1)
			dest[i] = src[i];
		dest[i] = 0;
	}
	return (ft_strlen(src));
}
