/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:09:57 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 17:17:57 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	delete_single_quotes(t_minishell *data,
		t_command_and_flag *command, int i)
{
	int	len;
	int	k;
	int	j;

	len = 0;
	if (command->command[i] == '\'' && data->double_q != 1)
	{
		if (data->single_q == 0)
			data->single_q = 1;
		else
			data->single_q = 0;
		j = i;
		k = 0;
		len = ft_strlen(&command->command[i]);
		while (k < len)
		{
			command->command[j] = command->command[j + 1];
			j++;
			k++;
		}
	}
	return (0);
}

int	delete_double_quotes(t_minishell *data,
		t_command_and_flag *command, int i)
{
	int	len;
	int	k;
	int	j;

	if (command->command[i] == '\"' && data->single_q != 1)
	{
		if (data->double_q == 0)
			data->double_q = 1;
		else
			data->double_q = 0;
		j = i;
		k = 0;
		len = ft_strlen(&command->command[i]);
		while (k < len)
		{
			command->command[j] = command->command[j + 1];
			j++;
			k++;
		}
	}
	return (0);
}

int	delete_quotes(t_minishell *data, t_command_and_flag *command)
{
	int	i;

	i = 0;
	data->single_q = 0;
	data->double_q = 0;
	while (command->command[i])
	{
		delete_single_quotes(data, command, i);
		delete_double_quotes(data, command, i);
		if (command->command[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
