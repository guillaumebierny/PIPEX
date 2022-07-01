/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:11:01 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/11 13:17:37 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*dest_bis;
	unsigned char	*src_bis;
	long int		i;

	i = 0;
	dest_bis = (unsigned char *)dest;
	src_bis = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (size--)
	{
		dest_bis[i] = src_bis[i];
		i++;
	}
	return (dest_bis);
}
