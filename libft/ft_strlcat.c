/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:31:55 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/11 13:23:29 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	j = -1;
	i = dest_len;
	if (size - 1 >= dest_len && size != 0)
	{
		while (src[++j] && dest_len < (size--) - 1)
			dest[i++] = src[j];
		dest[i] = 0;
	}
	else
		dest_len = size;
	return (dest_len + src_len);
}
