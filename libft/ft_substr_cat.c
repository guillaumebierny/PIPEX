/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:18:27 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/13 00:02:50 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_cat(char **dest, char *src)
{
	int		i;
	char	*new_dest;
	size_t	src_len;

	if (!*dest && !src)
		src_len = ft_strlen(src);
	i = 0;
	while (dest)
		i++;
	while (src)
		i++;
	new_dest = malloc(sizeof(char) * (i + 1));
	ft_strlcat(new_dest, (const char *)src, src_len + 1);
	ft_strlcat(new_dest, (const char *)dest, src_len + ft_strlen(*dest) + 1);
	if (*dest)
		free(*dest);
	return (new_dest);
}
