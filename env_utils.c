/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:59:15 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 15:42:01 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_env_lvl(t_env *env, int lvl)
{
	int		i;
	int		i1;
	char	*new_lvl;
	char	*tmp;

	i = 0;
	i1 = 0;
	new_lvl = ft_itoa(lvl);
	while (env->env[i])
	{
		if (ft_strnstr(env->env[i], "SHLVL", ft_strlen("SHLVL")))
		{
			while (env->env[i][i1] != '=')
				i1++;
			i1++;
			env->env[i][i1] = '\0';
			tmp = env->env[i];
			env->env[i] = ft_strjoin(env->env[i], new_lvl);
			free(tmp);
		}
		break ;
		i++;
	}
	free(new_lvl);
	return (0);
}

t_env	*env_keys_values(t_env *env1, int lvl, int i)
{
	int		i1;
	char	*tmp;

	while (env1->env[++i])
	{
		i1 = 0;
		while (env1->env[i][i1] != '=')
			i1++;
		env1->env[i][i1] = '\0';
		env1->keys[i] = ft_strdup(env1->env[i]);
		env1->env[i][i1] = '=';
		if (!ft_strncmp(env1->keys[i], "SHLVL", 6))
		{
			env1->env[i][i1 + 1] = '\0';
			env1->values[i] = ft_itoa(lvl + 1);
			tmp = env1->env[i];
			env1->env[i] = ft_strjoin(tmp, env1->values[i]);
			free(tmp);
		}
		else
			env1->values[i] = ft_strdup(&env1->env[i][++i1]);
	}
	env1->values[i] = NULL;
	env1->keys[i] = NULL;
	return (env1);
}

char	**ft_strdup_array_of_strings(char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (0);
	i = -1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = env[i];
	return (new_env);
}

t_env	*allocate_env(char **env, int lvl)
{
	t_env	*env1;
	int		i;

	i = 0;
	env1 = malloc(sizeof(t_env));
	if (env1 == NULL)
		return (NULL);
	env1->env = ft_strdup_array_of_strings(env);
	env1->env_lvl = 0;
	while (env[i])
		i++;
	env1->keys = (char **)malloc(sizeof(char *) * (i + 1));
	if (env1->keys == NULL)
		return (NULL);
	env1->values = (char **)malloc(sizeof(char *) * (i + 1));
	if (env1->values == NULL)
		return (NULL);
	i = -1;
	env1 = env_keys_values(env1, lvl, i);
	env1->exit_num = 0;
	return (env1);
}
