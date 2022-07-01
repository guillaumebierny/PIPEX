/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:33:01 by gbierny           #+#    #+#             */
/*   Updated: 2022/06/28 22:33:48 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *p, char **envp)
{
	p->pcmd1 = parsing(p->ev, p->fcmd[0]);
	dup2(p->tube[1], STDOUT_FILENO);
	close(p->tube[0]);
	dup2(p->fd[0], 0);
	execve(p->pcmd1, p->fcmd, envp);
	error_message("probleme avec l'exec 1\n");
}

void	second_child(t_pipex *p, char **envp)
{
	dup2(p->fd[1], 1);
	dup2(p->tube[0], 0);
	close(p->tube[1]);
	p->pcmd2 = parsing(p->ev, p->scmd[0]);
	execve(p->pcmd2, p->scmd, envp);
	error_message("problem avec l'exec 2");
}
