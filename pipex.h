/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:57:13 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/28 22:45:13 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct s_parsing
{
	int		i;
	int		j;
	int		k;
	char	*path;
}			t_parsing;

typedef struct s_pipex
{
	int		fd[2];
	int		pid1;
	int		pid2;
	char	*ev;
	int		x;
	int		tube[2];
	char	**fcmd;
	char	**scmd;
	char	*pcmd1;
	char	*pcmd2;
}			t_pipex;

//CHILD_C:
void	first_child(t_pipex *p, char **envp);
void	second_child(t_pipex *p, char **envp);
//PIPEX_UTILS_C:
void	error_message(char *s);
void	free_path_cmd(char **tab);
char	*parse_envp(char **envp);
char	*join_cmd_path(t_parsing v, char *s, char *cmd);
char	*parsing(char *s, char *cmd);

#endif
