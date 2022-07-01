/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:04:54 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/06 18:35:03 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		is_line(char *line);
int		sec_fix_whole_line(char *line);
int		sec_join(char *line, size_t buff_len);
int		sec_malloc(char *line, char *new_line);
int		malloc_empty_line(char **line, char *buffer);

#endif
