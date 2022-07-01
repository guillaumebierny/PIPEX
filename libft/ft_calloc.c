/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:09:40 by gbierny           #+#    #+#             */
/*   Updated: 2022/01/11 13:14:12 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	len_tab;
	size_t	i;

	i = -1;
	len_tab = (size) * (count);
	tab = (char *)malloc(len_tab);
	if (!tab)
		return (NULL);
	while (++i < len_tab)
		tab[i] = 0;
	return (tab);
}
