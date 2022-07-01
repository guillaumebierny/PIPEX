/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:34:23 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/28 22:36:02 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char *s)
{
	write(2, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}

void	free_path_cmd(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}

char	*parse_envp(char **envp)
{
	int	x;

	x = 0;
	while (envp[x])
	{
		if (ft_strnstr(envp[x], "PATH=", 5))
			return (envp[x]);
		x++;
	}
	return (NULL);
}

char	*join_cmd_path(t_parsing v, char *s, char *cmd)
{
	while (++v.k <= v.j - 2)
		v.path[v.k] = s[v.i + v.k + 1];
	v.path[v.k] = 0;
	v.path = ft_strjoin(v.path, "/");
	v.path = ft_strjoin(v.path, cmd);
	if (!access(v.path, 0))
		return (v.path);
	return (NULL);
}
