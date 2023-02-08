/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:48:14 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 18:18:51 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	split_flags_variables(int *i, int *j, int *l, int *k)
{
	*i = 0;
	*j = 0;
	*l = 1;
	*k = 0;
	return (0);
}

int	split_flags_utils(t_command_and_flag *one_command, int *l, int *i, int *k)
{
	if (*l == 1)
	{
		while (one_command->flags[*i] == ' ')
			(*i)++;
		*k = *i;
		*l = 0;
	}
	return (0);
}

int	split_flags_utils2(t_command_and_flag *one_command, \
		t_minishell *data, int *i, int *j)
{
	if (one_command->flags[*i] == '\'' && data->double_q == 0)
	{
		if (data->single_q == 0)
			data->single_q = 1;
		else
			data->single_q = 0;
		if (one_command->flags[(*i) + 1] == '\0')
			(*j)++;
		(*i)++;
		return (1);
	}
	if (one_command->flags[*i] == '\"' && data->single_q == 0)
	{
		if (data->double_q == 0)
			data->double_q = 1;
		else
			data->double_q = 0;
		if (one_command->flags[(*i) + 1] == '\0')
			(*j)++;
		(*i)++;
		return (1);
	}
	return (0);
}

int	split_flags_utils3(int *j, int *l)
{
	(*j)++;
	*l = 1;
	return (0);
}

int	split_flags(t_command_and_flag *one_command, t_minishell *data)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	key;

	split_flags_variables(&i, &j, &l, &k);
	while (one_command->flags[i])
	{
		key = 0;
		split_flags_utils(one_command, &l, &i, &k);
		key = split_flags_utils2(one_command, data, &i, &j);
		if (key == 1)
			continue ;
		if ((one_command->flags[i] == ' ' && data->single_q != 1 && \
		data->double_q != 1 && i != k) || (one_command->flags[i + 1] == '\0'))
			split_flags_utils3(&j, &l);
		i++;
	}
	one_command->array_flags = (char **)malloc(sizeof(char *) * (j + 2));
	if (one_command->array_flags == NULL)
		return (-1);
	return (0);
}
