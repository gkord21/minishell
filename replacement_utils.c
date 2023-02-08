/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacement_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:07:56 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:44:30 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	replacement_utils(t_minishell *data, char **env_varianles)
{
	int	len_env;

	if (data->env->exit_num == 0)
	{
		len_env = 1;
		*env_varianles = (char *)malloc(sizeof(char) * len_env + 1);
		if (*env_varianles == NULL)
			return (0);
		(*env_varianles)[0] = '0';
		(*env_varianles)[1] = '\0';
	}
	return (0);
}

int	replacement_utils_2(t_minishell *data, char **env_varianles)
{
	int	len_env;
	int	a;

	len_env = 0;
	a = data->env->exit_num;
	while (a > 0)
	{
		a = a / 10;
		len_env++;
	}
	*env_varianles = (char *)malloc(sizeof(char) * len_env + 1);
	if (env_varianles == NULL)
		return (0);
	(*env_varianles)[len_env] = '\0';
	len_env--;
	while (len_env > -1)
	{
		(*env_varianles)[len_env] = \
				(data->env->exit_num % 10) + '0';
		data->env->exit_num = \
				data->env->exit_num / 10;
		len_env--;
	}
	return (0);
}

int	replacement_utils_3(char **env_varianles)
{
	*env_varianles = (char *)malloc(sizeof(char) * 1);
	if (*env_varianles == NULL)
		return (0);
	(*env_varianles)[0] = '\0';
	return (0);
}

int	replacement_utils_4(char *command, int *i, int j)
{
	int	c;
	int	k;
	int	a;
	int	len_command;

	c = *i;
	k = j;
	a = c - j;
	len_command = ft_strlen(command);
	while (k + a < len_command)
	{
		command[k] = command[k + a];
		k++;
	}
	command[k] = '\0';
	return (0);
}

int	replacement_utils_5(char *command,
			char *new_command, int j, char *env_varianles)
{
	int	k;
	int	a;
	int	c;
	int	len_command;
	int	len_env;

	k = 0;
	a = 0;
	c = j;
	len_command = ft_strlen(command);
	len_env = ft_strlen(env_varianles);
	while (k < len_command + len_env + 1)
	{
		if (k < (j - 1))
			new_command[k] = command[k];
		if (k > (j - 1) && k < j + len_env)
			new_command[k - 1] = env_varianles[a++];
		if (k > j + len_env && command[c] != '\0')
			new_command[k - 2] = command[c++];
		k++;
	}
	new_command[k - 2] = '\0';
	return (j + len_env - 2);
}
