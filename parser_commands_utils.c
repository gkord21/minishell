/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:10:09 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 17:58:50 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_slash(char *command, int *i)
{
	if (command[*i] == '\\')
	{
		(*i)++;
		if (command[*i] == '\'' || command[*i] == '\"' || \
			command[*i] == '\\' || command[*i] == '$')
			(*i)++;
	}
	return (0);
}

int	shift_command(char *command, t_minishell *data)
{
	int		i;
	int		fd;
	char	a[5];

	fd = open(data->file_history, O_RDWR);
	if (fd == -1)
		return (-1);
	i = 1;
	while (i != 0)
		i = read(fd, a, 1);
	if (data->flag == 1)
	{
		write(fd, "\n", 1);
		write(fd, command, ft_strlen(command));
		data->flag = 0;
	}
	else
	{
		write(fd, "\n", 1);
		write(fd, command, ft_strlen(command));
	}
	close(fd);
	return (0);
}

int	skip_space(t_command_and_flag *one_command, \
		int *i, int *j, int *len)
{
	*i = 0;
	*j = 0;
	*len = ft_strlen(one_command->command_and_flags);
	while (one_command->command_and_flags[*i] == ' ' || \
			one_command->command_and_flags[*i] == '	')
		(*i)++;
	*j = *i;
	return (0);
}

int	fill_command(t_command_and_flag *one_command, \
		int *i, int *j, t_minishell *data)
{
	int	k;

	one_command->command = (char *)malloc(sizeof(char) * (*i - *j) + 1);
	if (one_command->command == NULL)
		return (-1);
	k = 0;
	while (*j < *i)
	{
		one_command->command[k] = one_command->command_and_flags[*j];
		(*j)++;
		k++;
	}
	one_command->command[*j] = '\0';
	delete_quotes(data, one_command);
	return (0);
}

int	fill_flags(t_command_and_flag *one_command, int len, int *i)
{
	int	j;

	j = 0;
	one_command->flags = (char *)malloc(sizeof(char) * (len - *i + 1));
	if (one_command->flags == NULL)
		return (-1);
	while ((*i) < len)
	{
		one_command->flags[j] = one_command->command_and_flags[*i];
		j++;
		(*i)++;
	}
	one_command->flags[j] = '\0';
	return (0);
}
