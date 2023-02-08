/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stat_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:03:48 by iwhana21          #+#    #+#             */
/*   Updated: 2022/06/04 04:41:12 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_stat_file_utils(t_command_and_flag *command,
		int *i_stat, struct stat stat_command)
{
	if (*(i_stat) == 0)
	{
		if (S_ISREG(stat_command.st_mode))
		{
			if (command->pape == LESS)
			{
				if ((stat_command.st_mode & S_IRUSR) != S_IRUSR)
					return (-3);
			}
			else
			{
				if ((stat_command.st_mode & S_IWUSR) != S_IWUSR)
					return (-3);
			}
		}
		else
			*(i_stat) = -2;
	}
	else
		*(i_stat) = create_file(command->command);
	return (0);
}

int	check_stat_file(t_command_and_flag *command)
{
	int			i_stat;
	struct stat	stat_command;
	int			len;
	char		buf[32000];
	char		*tmp;

	i_stat = -1;
	if (find_slash_dot(command->command) == 1)
		i_stat = check_stat_file_with_path(command);
	else
	{
		getcwd(buf, 32000);
		len = ft_strlen(buf);
		buf[len] = '/';
		len++;
		buf[len] = '\0';
		tmp = command->command;
		command->command = ft_strjoin(buf, command->command);
		free(tmp);
		i_stat = stat(command->command, &stat_command);
		check_stat_file_utils(command, &i_stat, stat_command);
	}
	return (i_stat);
}

int	find_slash_dot(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 47)
			return (1);
		else if (line[i] == '.')
			return (1);
	}
	return (0);
}

int	check_stat_command_with_path(t_command_and_flag *command)
{
	int				i_stat;
	struct stat		stat_command;

	i_stat = 0;
	i_stat = stat(command->command, &stat_command);
	{
		if (i_stat == 0)
		{
			if (S_ISREG(stat_command.st_mode))
			{
				if ((stat_command.st_mode & S_IXUSR) == S_IXUSR)
					return (i_stat);
				else
					i_stat = -1;
			}
			else
				i_stat = -1;
		}
	}
	return (i_stat);
}

int	check_stat_command_utils_2(struct stat stat_command)
{
	int	i_stat;

	i_stat = 0;
	if (S_ISREG(stat_command.st_mode))
	{
		if ((stat_command.st_mode & S_IXUSR) == S_IXUSR)
			i_stat = 0;
		else
			i_stat = -1;
	}
	else
		i_stat = -1;
	return (i_stat);
}
