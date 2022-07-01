/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:38:13 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/24 21:11:30 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fix_whole_line(char *line)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!sec_fix_whole_line(line))
		return (0);
	while (line && line[i] && line[i] != '\n')
		i++;
	if (line && line[i] == '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (0);
	i = -1;
	while (line[++i] != '\n' && line && line[i])
		new_line[i] = line[i];
	if (line && line[i] == '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = 0;
	free(line);
	return (new_line);
}

char	*join(char *line, char *buffer, size_t buff_len)
{
	char	*new_line;
	int		i;
	size_t	j;

	j = -1;
	i = 0;
	if (!sec_join(line, buff_len))
		return (0);
	if (!malloc_empty_line(&line, buffer))
		return (0);
	while (line && line[i])
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + buff_len + 1));
	if (!sec_malloc(line, new_line))
		return (0);
	i = -1;
	while (line[++i])
		new_line[i] = line[i];
	while (++j < buff_len)
		new_line[i + j] = buffer[j];
	new_line[i + j] = 0;
	free(line);
	return (new_line);
}

char	*new_line(char *buffer, char *line)
{
	int		i;
	int		j;
	char	*new_line;

	if (!buffer)
		return (0);
	new_line = NULL;
	j = 0;
	if (is_line(line) >= 0)
	{
		i = is_line(line) + 1;
		while (line[i + j])
			j++;
		new_line = malloc(sizeof(char) * (j + 1));
		if (!new_line)
			return (0);
		new_line[j] = 0;
		while (j--)
			new_line[j] = line[i + j];
		return (new_line);
	}
	return (0);
}

int	sub_get_next_line(char **rest, char **line, int *fd)
{
	char	*buffer;
	size_t	buff_len;

	buff_len = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (is_line(*line) < 0 && buff_len > 0)
	{
		if (is_line(*line) < 0)
		{
			buff_len = read(*fd, buffer, BUFFER_SIZE);
			buffer[buff_len] = 0;
		}
		if (buff_len > 0)
			*line = join(*line, buffer, buff_len);
	}
	*rest = new_line(buffer, *line);
	*line = fix_whole_line(*line);
	free(buffer);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	line = NULL;
	line = rest;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, line, 0))
		return (0);
	if (sub_get_next_line(&rest, &line, &fd))
		return (line);
	else
		return (0);
}
