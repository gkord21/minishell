/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:23:17 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:41:28 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_command_with_env_variables_utils_3(char **command, \
		t_minishell *data, int *i, int *j)
{
	data->name_varianled = create_command(*command, *i, *j, 0);
	data->env_varianles = my_getenv(data->name_varianled, \
			data);
	if ((*command)[(*j) - 2] == '"')
		data->tmp = replacement(*command, i, --(*j), data);
	else
		data->tmp = replacement(*command, i, *j, data);
	*command = data->tmp;
	data->double_q = 0;
	free(data->name_varianled);
	return (0);
}

int	create_command_with_env_variables_utils_2(char *command, \
		int *i, int *j)
{
	(*i)++;
	*j = *i;
	while (command[*i] != ' ' && command[*i] != '\0')
		(*i)++;
	return (0);
}

int	create_command_with_env_variables_utils(char *command, \
		t_minishell *data, int *i)
{
	if (command[*i] == '\\')
	{
		(*i)++;
		if (command[*i] == '\'' || command[*i] == '\"' \
				|| command[*i] == '\\' || command[*i] == '$')
			(*i)++;
	}
	if (command[*i] == '\'' && data->double_q == 0)
	{
		if (data->single_q == 0)
			data->single_q = 1;
		else
			data->single_q = 0;
		(*i)++;
	}
	if (command[*i] == '\"' && data->single_q == 0)
	{
		if (data->double_q == 0)
			data->double_q = 1;
		else
			data->double_q = 0;
		(*i)++;
	}
	return (0);
}

char	*create_command_with_env_variables(char *command, \
		t_minishell *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->tmp = NULL;
	while (command[i])
	{
		create_command_with_env_variables_utils(command, data, &i);
		if (command[i] == '$' && data->single_q != 1)
		{
			create_command_with_env_variables_utils_2(command, \
					&i, &j);
			if (!ft_strnstr(command, "unset", ft_strlen(command)))
				create_command_with_env_variables_utils_3(&command, \
					data, &i, &j);
		}
		if (command[i] == '\0')
			break ;
		i++;
	}
	if (data->tmp != NULL)
		free(data->tmp);
	return (command);
}
