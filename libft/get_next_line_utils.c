/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:18:03 by gbierny           #+#    #+#             */
/*   Updated: 2022/02/02 17:59:30 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line(char *line)
{
	int	i;

	if (!line)
		return (-2);
	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n')
			return (i);
	}
	return (-1);
}

int	sec_fix_whole_line(char *line)
{
	if (!line)
		return (0);
	if (!line[0])
	{
		free(line);
		return (0);
	}
	return (1);
}

int	sec_join(char *line, size_t buff_len)
{
	if (!line && !buff_len)
		return (0);
	if (line && !buff_len)
		return (0);
	return (1);
}

int	sec_malloc(char *line, char *new_line)
{
	if (!new_line)
	{
		free(line);
		return (0);
	}
	return (1);
}

int	malloc_empty_line(char **line, char *buffer)
{
	if (!(*line) && buffer)
	{
		*line = malloc(sizeof(char) * 1);
		if (!(*line))
			return (0);
		(*line)[0] = 0;
	}
	return (1);
}
