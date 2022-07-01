/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:32:42 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/13 15:33:08 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*putnbr(long int nb, char *dest, size_t i)
{
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
	}
	if (nb < 10)
	{
		dest[i] = (char)(nb % 10 + 48);
	}
	else if (nb >= 10)
	{
		putnbr(nb / 10, dest, i - 1);
		dest[i] = (char)(nb % 10 + 48);
	}
	dest[i + 1] = 0;
	return (dest);
}

char	*ft_itoa(int n)
{
	long int	nb;
	size_t		size;
	char		*dest;

	if (!n)
	{
		dest = ft_calloc(2, sizeof(char));
		dest[0] = '0';
		return (dest);
	}
	nb = (long int)n;
	size = 0;
	if (n < 0)
		size++;
	while (nb != 0)
	{
		nb /= 10;
		size++;
	}
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	putnbr((long int)n, dest, size - 1);
	return (dest);
}
