/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:01:01 by iwhana21          #+#    #+#             */
/*   Updated: 2022/06/04 04:41:20 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_stat_command_utils(t_minishell *data,
		t_command_and_flag *command, char **path_and_command)
{
	struct stat		stat_command;
	int				i;
	int				i_stat;

	i = 0;
	i_stat = -1;
	while (data->path[i])
	{
		*path_and_command = ft_strjoin(data->path[i],
				command->command);
		i_stat = stat(*path_and_command, &stat_command);
		if (i_stat == 0)
		{
			i_stat = check_stat_command_utils_2(stat_command);
			break ;
		}
		i++;
		free(*path_and_command);
		*path_and_command = NULL;
	}
	return (i_stat);
}

int	check_stat_command(t_minishell *data, t_command_and_flag *command)
{
	int				i_stat;
	char			*path_and_command;

	path_and_command = NULL;
	i_stat = -1;
	if (find_slash_dot(command->command) == 1)
		i_stat = check_stat_command_with_path(command);
	else
	{
		if (data->path == NULL)
			return (i_stat);
		i_stat = check_stat_command_utils(data,
				command, &path_and_command);
	}
	if (path_and_command != NULL)
	{
		free (command->command);
		command->command = path_and_command;
	}
	return (i_stat);
}

int	stat_command_utils(t_command_and_flag *command, int *i_stat, \
		t_minishell *data)
{
	if (command->pape == DOUBLE_MORE || \
		command->pape == MORE || command->pape == LESS)
		*i_stat = check_stat_file(command);
	else
		*i_stat = check_stat_command(data, command);
	command->f_error = *i_stat;
	return (0);
}

int	check_stat_builtins(t_command_and_flag *command)
{
	int	stat;

	stat = -1;
	if (!ft_strncmp(command->command, "echo", 4) || \
	!ft_strncmp(command->command, "cd", 2) || \
	!ft_strncmp(command->command, "pwd", 3) || \
	!ft_strncmp(command->command, "minishell", 9) || \
	!ft_strncmp(command->command, "export", 6) || \
	!ft_strncmp(command->command, "unser", 5) || \
	!ft_strncmp(command->command, "env", 3) || \
	!ft_strncmp(command->command, "exit", 4))
	{
		stat = 1;
	}
	return (stat);
}

int	*stat_command(t_minishell *data)
{
	int					i_stat;
	t_command_and_flag	*command;

	command = data->head;
	while (command)
	{
		i_stat = -1;
		if (check_stat_builtins(command) == 1)
		{
			command->f_error = 0;
			command = command->next;
			continue ;
		}
		if (command->pape == DOUBLE_LESS)
		{
			i_stat = 0;
			command = command->next;
			continue ;
		}
		stat_command_utils(command, &i_stat, data);
		command = command->next;
	}
	return (0);
}
