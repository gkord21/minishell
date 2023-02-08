/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:30:15 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:42:30 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tmp(t_command_and_flag	*tmp)
{	
	int	i;

	i = -1;
	free(tmp->command);
	while (tmp->array_flags[++i])
		free(tmp->array_flags[i]);
	free(tmp->array_flags[i]);
	free(tmp->array_flags);
	free(tmp);
}

void	free_env(t_minishell *data, t_env *env)
{
	int	i;

	i = 0;
	free(data->file_history);
	while (env->env[i])
	{
		free(env->env[i]);
		free(env->keys[i]);
		free(env->values[i]);
		i++;
	}
	free(env->env);
	free(env->keys);
	free(env->values);
	i = 0;
	if (env->env_lvl != NULL)
	{
		while (env->env_lvl[i])
		{
			free(env->env_lvl[i]);
			i++;
		}
		free(env->env_lvl);
	}
	free(env);
}

void	free_path(t_minishell *data)
{
	int					i;
	t_command_and_flag	*command;

	data->single_q = 0;
	data->double_q = 0;
	command = data->head;
	free_commands(command);
	if (data->path != NULL)
	{
		i = 0;
		while (data->path[i])
		{
			free(data->path[i]);
			i++;
		}
		free(data->path);
	}
	data->head = NULL;
}

int	free_commands(t_command_and_flag *command)
{
	t_command_and_flag	*tmp;
	int					i;

	while (command)
	{
		free(command->command_and_flags);
		free(command->command);
		free(command->flags);
		i = 1;
		if (command->array_flags != NULL)
		{	
			while (command->array_flags[i])
			{
				free(command->array_flags[i]);
				i++;
			}
			free(command->array_flags);
		}
		tmp = command->next;
		free(command);
		command = tmp;
	}
	return (0);
}
