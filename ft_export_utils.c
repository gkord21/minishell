/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:19:10 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 17:58:19 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_env(t_env *env, char *str, int end, int value)
{
	int		i;
	char	*tmp;

	i = -1;
	while (env->keys[++i])
	{
		if (!ft_strncmp(str, env->keys[i], end) && \
		ft_strlen(env->keys[i]) == (size_t)end)
		{
			if (value && ft_strncmp(&str[end + 1], env->values[i], \
			ft_strlen(env->values[i])) && ft_strncmp(&str[end + 1], \
			env->values[i], ft_strlen(&str[end + 1])))
			{
				tmp = env->values[i];
				env->values[i] = ft_strdup(&str[end + 1]);
				free(tmp);
				free(env->env[i]);
				tmp = ft_strjoin(env->keys[i], "=");
				env->env[i] = ft_strjoin(tmp, env->values[i]);
				free(tmp);
			}
			return (0);
		}
	}
	return (1);
}

int	ft_check_env_lvl(t_env *struct_env, char *str, \
	int end_of_key,	int value)
{
	int	i;

	i = -1;
	while (struct_env->env_lvl && struct_env->env_lvl[++i])
	{
		if (!ft_strncmp(str, struct_env->env_lvl[i], end_of_key) && \
		struct_env->env_lvl[i][end_of_key] == '\0')
		{
			if (value)
			{
				struct_env->env_lvl = new_array_rm(struct_env->env_lvl, i);
				str[end_of_key] = '\0';
				struct_env->keys = new_array_add(struct_env->keys, str);
				struct_env->values = new_array_add(struct_env->values, \
				&str[end_of_key + 1]);
				str[end_of_key] = '=';
				struct_env->env = new_array_add(struct_env->env, str);
			}
			return (0);
		}
	}
	return (1);
}

void	ft_value_name(char *str, int *end_of_key, int *value)
{
	*end_of_key = 0;
	while (str[*end_of_key] && str[*end_of_key] != '=')
		(*end_of_key)++;
	if (str[*end_of_key] == '=')
		*value = ft_strlen(str) - 1;
	else
		*value = 0;
	str[*end_of_key] = '\0';
	if (!ft_check_name(str))
	{
		if (*value)
			str[*end_of_key] = '=';
		return ;
	}
	if (*value)
		str[*end_of_key] = '=';
}
