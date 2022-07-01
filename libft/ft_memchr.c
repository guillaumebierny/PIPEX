/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:10:20 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/11 13:20:09 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*blk_bis;
	unsigned char	search_bis;

	search_bis = (unsigned char)c;
	blk_bis = (unsigned char *)s;
	i = 0;
	if (!n)
		return (NULL);
	while (--n && n)
	{
		if (blk_bis[i] == search_bis)
			return (blk_bis + i);
		i++;
	}
	if (blk_bis[i] == search_bis)
		return (blk_bis + i);
	return (NULL);
}
