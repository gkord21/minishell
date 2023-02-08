/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:42:58 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 15:23:31 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser_flags_utils4(t_command_and_flag *one_command, \
		t_minishell *data, int k)
{
	one_command->array_flags[k] = NULL;
	delete_quotes_in_flags(data);
	return (0);
}

int	parser_flags_utils3(t_command_and_flag *one_command, \
		int *i, int *j, int *k)
{
	int	z;
	int	key;

	key = 0;
	z = 0;
	if (one_command->flags[*i + 1] == '\0' && one_command->flags[*i] != ' ')
	{
		(*i)++;
		key = 1;
	}
	one_command->array_flags[*k] = (char *)malloc(sizeof(char) * \
			((*i) - (*j) + 1));
	if (one_command->array_flags[*k] == NULL)
		return (-1);
	while (*j < *i)
	{
		one_command->array_flags[*k][z++] = one_command->flags[*j];
		(*j)++;
	}
	one_command->array_flags[*k][z] = '\0';
	(*k)++;
	(*j) = (*i);
	if (key == 1)
		(*i)--;
	return (0);
}

int	parser_flags_utils2(t_command_and_flag *one_command, \
		t_minishell *data)
{
	split_flags(one_command, data);
	one_command->array_flags[0] = one_command->command;
	data->single_q = 0;
	data->double_q = 0;
	return (0);
}

int	parser_flags_utils(int *i, int *j, int *k, int *z)
{
	*i = 0;
	*k = 1;
	*j = 0;
	*z = 0;
	return (0);
}

int	parser_flags(t_minishell *data, t_command_and_flag *one_command)
{
	int	i;
	int	j;
	int	k;
	int	z;

	while (one_command)
	{
		parser_flags_utils(&i, &j, &k, &z);
		parser_flags_utils2(one_command, data);
		while (one_command->flags[i])
		{
			skip_space_flags(one_command, &j, &i);
			if (one_command->flags[j] == '\0')
				break ;
			parser_flags_quotes(one_command, data, &i);
			if ((one_command->flags[i] == ' ' && data->single_q != 1 \
				&& data->double_q != 1 && j != i) || \
				(one_command->flags[i + 1] == '\0'))
				parser_flags_utils3(one_command, &i, &j, &k);
			i++;
		}
		parser_flags_utils4(one_command, data, k);
		one_command = one_command->next;
	}
	return (0);
}
