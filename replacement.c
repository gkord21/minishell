/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:06:25 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:44:34 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replacement_2(char *command, int *i, int j, t_minishell *data)
{
	int		len_env;
	int		len_command;
	char	*new_command;

	len_command = ft_strlen(command);
	len_env = ft_strlen(data->env_varianles);
	replacement_utils_4(command, i, j);
	len_env = ft_strlen(data->env_varianles);
	len_command = ft_strlen(command);
	new_command = (char *)malloc(sizeof(char) * (len_command + len_env + 1));
	if (new_command == NULL)
		return (NULL);
	*i = replacement_utils_5(command, new_command,
			j, data->env_varianles);
	if (data->name_varianled[0] == '?' && \
			ft_strlen(data->name_varianled) == 1)
		free(data->env_varianles);
	return (new_command);
}

char	*replacement(char *command, int *i, int j, t_minishell *data)
{
	char	*new_command;

	if (data->env_varianles == NULL)
	{
		if (data->name_varianled[0] == '?' && \
				ft_strlen(data->name_varianled) == 1)
		{
			if (data->env->exit_num == 0)
				replacement_utils(data, &data->env_varianles);
			else
				replacement_utils_2(data, &data->env_varianles);
		}
		else
			replacement_utils_3(&data->env_varianles);
	}
	new_command = replacement_2(command, i, j, data);
	return (new_command);
}
