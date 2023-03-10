/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:45:08 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:41:08 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_double_less_print(t_command_and_flag *all, int fd)
{
	int	i;

	i = 1;
	while (all->array_flags[i])
	{
		ft_putstr_fd(all->array_flags[i++], fd);
		ft_putchar_fd('\n', fd);
	}
	exit(0);
}

void	check_builtins2(t_command_and_flag *all, int *pipe_1, \
int fd1, t_env *env)
{
	if (!ft_strncmp(all->command, "cd", 3))
		exit(ft_cd(all, env->env));
	if (!ft_strncmp(all->command, "unset", 6))
		exit(ft_unset(all, env));
	if (!ft_strncmp(all->command, "export", 7) && fd1)
		exit(ft_export(all, fd1, env));
	if (!ft_strncmp(all->command, "export", 7) && pipe_1 != 0)
		exit(ft_export(all, pipe_1[1], env));
	if (!ft_strncmp(all->command, "export", 7))
		exit(ft_export(all, 0, env));
	if (all->pape == DOUBLE_LESS && fd1)
		ft_double_less_print(all, fd1);
	if (all->pape == DOUBLE_LESS && pipe_1 != 0)
		ft_double_less_print(all, pipe_1[1]);
	if (all->pape == DOUBLE_LESS)
		ft_double_less_print(all, 0);
}

void	check_builtins(t_command_and_flag *all, \
int *pipe_1, int fd1, t_env *env)
{
	if (!ft_strncmp(all->command, "pwd", 4) && fd1)
		ft_pwd(env->env, fd1);
	if (!ft_strncmp(all->command, "pwd", 4) && pipe_1 != 0)
		ft_pwd(env->env, pipe_1[1]);
	if (!ft_strncmp(all->command, "pwd", 4))
		ft_pwd(env->env, 0);
	if (!ft_strncmp(all->command, "env", 4) && fd1)
		ft_env(all, env->env, fd1);
	if (!ft_strncmp(all->command, "env", 4) && pipe_1 != 0)
		ft_env(all, env->env, pipe_1[1]);
	if (!ft_strncmp(all->command, "env", 4))
		ft_env(all, env->env, 0);
	if (!ft_strncmp(all->command, "echo", 5) && fd1)
		ft_echo(all, fd1);
	if (!ft_strncmp(all->command, "echo", 5) && pipe_1 != 0)
		ft_echo(all, pipe_1[1]);
	if (!ft_strncmp(all->command, "echo", 5))
		ft_echo(all, 0);
}
