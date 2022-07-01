/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:52:28 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/28 22:35:22 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

void	print_tab(char **tab)
{
	int	x;

	if (!tab)
		return ;
	x = 0;
	while (tab[x])
	{
		printf("%s\n", tab[x]);
		x++;
	}
}

char	*parsing(char *s, char *cmd)
{
	t_parsing	v;

	v.i = 0;
	while (s[v.i])
	{
		if (s[v.i] == ':')
		{
			v.j = 1;
			v.k = -1;
			while (s[v.i + v.j] != ':' && s[v.i + v.j])
				v.j++;
			v.path = malloc(sizeof(char) * v.j);
			if (!v.path)
				error_message("erreur de malloc");
			v.path = join_cmd_path(v, s, cmd);
			if (v.path)
				return (v.path);
			free(v.path);
		}
		v.i++;
	}
	error_message("command not found\n");
	return (NULL);
}

void	check_error_and_pipe(int tube[2], int argc, char **envp)
{
	if (pipe(tube) < 0)
		error_message("probleme de creation de tube\n");
	if (argc != 5)
		error_message("pas bons args ex:\n infile cmd1 cmd2 outfile");
	if (!envp)
		error_message("envp n'existe pas");
}

void	end_of_pipex(t_pipex *p)
{
	close(p->tube[0]);
	close(p->tube[1]);
	waitpid(p->pid1, NULL, 0);
	waitpid(p->pid2, NULL, 0);
	free_path_cmd(p->fcmd);
	free_path_cmd(p->scmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	p.x = 0;
	check_error_and_pipe(p.tube, argc, envp);
	p.fcmd = ft_split(argv[2], ' ');
	p.scmd = ft_split(argv[3], ' ');
	p.ev = parse_envp(envp);
	if (!p.ev)
		error_message("path introuvable dans envp");
	p.fd[0] = open(argv[1], O_RDONLY);
	if (p.fd[0] <= 0)
		error_message("infile non valide\n");
	p.fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	p.pid1 = fork();
	if (!p.pid1)
		first_child(&p, envp);
	p.pid2 = fork();
	if (!p.pid2)
		second_child(&p, envp);
	end_of_pipex(&p);
	return (0);
}
