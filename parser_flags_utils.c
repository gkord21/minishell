/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:11:56 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 18:00:31 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	delete_quotes_in_flags_utils(t_minishell *data, \
		t_command_and_flag *command, int i, int j)
{
	int	l;
	int	k;
	int	len;

	if (command->array_flags[i][j] == '\'' && data->double_q != 1)
	{
		if (data->single_q == 0)
			data->single_q = 1;
		else
			data->single_q = 0;
		l = j;
		k = 0;
		len = ft_strlen(&command->array_flags[i][j]);
		while (k < len + 1)
		{
			command->array_flags[i][l] = command->array_flags[i][l + 1];
			l++;
			k++;
		}
	}
	return (0);
}

int	delete_quotes_in_flags_utils2(t_minishell *data, \
		t_command_and_flag *command, int i, int j)
{
	int	l;
	int	k;
	int	len;

	if (command->array_flags[i][j] == '\"' && data->single_q != 1)
	{
		if (data->double_q == 0)
			data->double_q = 1;
		else
			data->double_q = 0;
		l = j;
		k = 0;
		len = ft_strlen(&command->array_flags[i][j]);
		while (k < len + 1)
		{
			command->array_flags[i][l] = command->array_flags[i][l + 1];
			l++;
			k++;
		}
	}
	return (0);
}

int	delete_quotes_in_flags(t_minishell *data)
{
	int					i;
	int					j;
	t_command_and_flag	*command;

	command = data->head;
	data->double_q = 0;
	data->single_q = 0;
	while (command)
	{
		i = -1;
		if (command->array_flags != NULL)
		{
			while (command->array_flags[++i])
			{
				j = -1;
				while (command->array_flags[i][++j])
				{
					delete_quotes_in_flags_utils(data, command, i, j);
					delete_quotes_in_flags_utils2(data, command, i, j);
				}
			}
		}
		command = command->next;
	}
	return (0);
}

int	skip_space_flags(t_command_and_flag *one_command, int *j, int *i)
{
	while (one_command->flags[*j] == ' ' || one_command->flags[*j] == '	')
	{
		(*j)++;
		(*i) = (*j);
	}
	return (0);
}

int	parser_flags_quotes(t_command_and_flag *one_command, \
		t_minishell *data, int *i)
{
	if (one_command->flags[*i] == '\'' && data->double_q == 0)
	{
		if (data->single_q == 0)
			data->single_q = 1;
		else
			data->single_q = 0;
	}
	if (one_command->flags[*i] == '\"' && data->single_q == 0)
	{
		if (data->double_q == 0)
			data->double_q = 1;
		else
			data->double_q = 0;
	}
	return (0);
}
