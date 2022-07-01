/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:53:48 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/11 12:42:46 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	size_t	i;
	char	*buff;

	buff = (char *)str;
	i = -1;
	while (++i < len)
	{
		(buff[i]) = (unsigned char)value;
	}
	return ((void *)buff);
}
