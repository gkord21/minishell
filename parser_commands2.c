/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:21:57 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:43:49 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser_pipe(char *command, int *i, int *j, \
		t_minishell *data)
{
	char	*new_command;

	if (command[*i] == '|')
	{
		new_command = create_command(command, *i, *j, 1);
		create_list_command(new_command, data, data->pipe);
		data->pipe = DIRECT_LINE;
		(*i)++;
		*j = *i;
	}
	return (0);
}

int	parser_quotes(t_minishell *data, \
		t_command_and_flag *one_command, int *i)
{
	if (one_command->command_and_flags[*i] == '\'' && \
		data->double_q == 0)
	{
		if (data->single_q == 0)
			data->single_q = 1;
		else
			data->single_q = 0;
	}
	if (one_command->command_and_flags[*i] == '\"' && \
		data->single_q == 0)
	{
		if (data->double_q == 0)
			data->double_q = 1;
		else
			data->double_q = 0;
	}
	return (0);
}

int	parser_redirection_out(char *command, int *i, int *j, \
		t_minishell *data)
{
	char	*new_command;

	if (command[*i] == '>')
	{
		if (command[*i + 1] == '>')
		{
			new_command = create_command(command, *i, *j, 1);
			create_list_command(new_command, data, data->pipe);
			data->pipe = DOUBLE_MORE;
			*i = *i + 2;
			*j = *i;
		}
		else
		{
			new_command = create_command(command, *i, *j, 1);
			create_list_command(new_command, data, data->pipe);
			data->pipe = MORE;
			(*i)++;
			*j = *i;
		}
	}
	return (0);
}

int	parser_redirection_in(char *command, int *i, int *j, \
		t_minishell *data)
{
	char	*new_command;

	if (command[*i] == '<')
	{
		if (command[*i + 1] == '<')
		{
			new_command = create_command(command, *i, *j, 1);
			create_list_command(new_command, data, data->pipe);
			data->pipe = DOUBLE_LESS;
			*i = *i + 2;
			*j = *i;
		}
		else
		{
			new_command = create_command(command, *i, *j, 1);
			create_list_command(new_command, data, data->pipe);
			data->pipe = LESS;
			(*i)++;
			*j = *i;
		}
	}
	return (0);
}
