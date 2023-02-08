/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:44:12 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:41:24 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	core_fork(t_command_and_flag	*all, int	*pipe_1, \
int	*pipe_2, t_env	*env)
{
	struct stat	buff;
	pid_t		pid;

	if (pipe_2 != 0)
		pipe(pipe_2);
	pid = fork();
	g_global_pid = pid;
	if (!pid)
	{
		check_builtins(all, pipe_1, env->fd[0], env);
		check_builtins2(all, pipe_1, env->fd[0], env);
		redirect_pipe(pipe_1, 1);
		redirect_pipe(pipe_2, 0);
		redirect_fd(env->fd[0], 1);
		redirect_fd(env->fd[1], 0);
		if (!ft_strncmp(all->command, "minishell", 10) || \
		!ft_strncmp(all->command, "exit", 5))
			exit(0);
		if (stat(all->command, &buff))
			exit(1);
		if (execve(all->command, all->array_flags, env->env))
			exit(0);
	}
	close_pipe(pipe_1);
	return (pid);
}
