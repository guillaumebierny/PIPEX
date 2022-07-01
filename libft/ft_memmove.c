/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:54:58 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/11 13:18:42 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*dest_bis;
	char	*src_bis;

	dest_bis = (char *)dest;
	src_bis = (char *)src;
	if (!dest && !src && !size)
		return (dest);
	if (dest_bis > src_bis)
	{
		while (size-- > 0)
			dest_bis[size] = src_bis[size];
	}
	else
		ft_memcpy(dest, src, size);
	return (dest_bis);
}
