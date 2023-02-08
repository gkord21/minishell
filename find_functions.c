/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:54:08 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 15:17:09 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**make_pipe(int size)
{
	int	**pipe;
	int	i;

	i = 0;
	if (size < 0)
		return (0);
	pipe = malloc(sizeof(int *) * (size + 2));
	if (!pipe)
		return (0);
	pipe[i++] = NULL;
	while (i <= size)
	{
		pipe[i] = malloc(sizeof(int) * 2);
		if (!pipe[i++])
			return (0);
	}
	pipe[size + 1] = NULL;
	return (pipe);
}

void	fd_init(t_env	*env, int flag)
{
	if (flag)
	{
		env->fd[0] = 0;
		env->fd[1] = 0;
	}
	else
	{
		if (env->fd[1] != 0)
			close(env->fd[1]);
		if (env->fd[0] != 0)
			close(env->fd[0]);
		env->fd[0] = 0;
		env->fd[1] = 0;
	}
}

void	free_find_function(int	**pipe, int	*pid)
{
	int	i;

	i = 0;
	free(pipe[i++]);
	while (pipe[i])
		free(pipe[i++]);
	free(pipe[i]);
	free(pipe);
	free(pid);
}

void	find_function(int size, t_env *env, t_command_and_flag *head, \
t_command_and_flag *reverse_head)
{
	int		**pipe;
	int		i;
	pid_t	*pid;

	i = 0;
	pipe = make_pipe(size);
	pid = malloc(sizeof(pid) * (size + 1));
	if (!pid)
		return ;
	fd_init(env, 1);
	while (i <= size)
	{
		if (head && (head->pape == MORE || head->pape == DOUBLE_MORE || \
		head->pape == LESS))
			redirect(head, &env->fd[0], &env->fd[1]);
		while (head && (head->pape == MORE || head->pape == \
		DOUBLE_MORE || head->pape == LESS))
			head = redirect2(head);
		pid[i] = core_fork(head, pipe[i], pipe[i + 1], env);
		head = head->next;
		fd_init(env, 0);
		i++;
	}
	print_errors(pid, reverse_head, size, env);
	free_find_function(pipe, pid);
}
