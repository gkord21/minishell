/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stat_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:05:17 by iwhana21          #+#    #+#             */
/*   Updated: 2022/06/04 04:41:15 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_stat_file_with_path_utils(t_command_and_flag *command,
		struct stat stat_command)
{
	int	i_stat;

	i_stat = 0;
	if (command->pape == LESS)
	{
		if ((stat_command.st_mode & S_IRUSR) == S_IRUSR)
			return (i_stat);
		else
			i_stat = -3;
	}
	else
	{
		if ((stat_command.st_mode & S_IWUSR) == S_IWUSR)
			return (i_stat);
		else
			i_stat = -3;
	}
	return (i_stat);
}

int	check_stat_file_with_path(t_command_and_flag *command)
{
	int			i_stat;
	struct stat	stat_command;

	i_stat = -1;
	i_stat = stat(command->command, &stat_command);
	if (i_stat == 0)
	{
		if (S_ISREG(stat_command.st_mode))
		{
			i_stat = check_stat_file_with_path_utils(command, stat_command);
		}
		else
		{
			i_stat = -2;
		}
	}
	return (i_stat);
}

int	create_file(char *path_and_command)
{
	int	fd;

	fd = open(path_and_command, O_WRONLY | O_CREAT, 0777 | O_TRUNC | O_APPEND);
	if (!fd)
		return (-1);
	else
		close (fd);
	return (0);
}
