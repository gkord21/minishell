/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:45:36 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:43:09 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_name(char *name)
{
	int	i;

	i = 0;
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	while (name[i] && name[i] != '=')
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	ft_unset_env_lvl(t_env *struct_env, char *str, int len)
{
	int	i;

	i = -1;
	while (struct_env->env_lvl[++i])
	{
		if (!ft_strncmp(struct_env->env_lvl[i], str, len) && \
		struct_env->env_lvl[i][len] == '\0')
		{
			struct_env->env_lvl = new_array_rm(struct_env->env_lvl, i);
			break ;
		}
	}
}

void	ft_unset_loop(char	*str, t_env	*struct_env)
{
	int	len;
	int	i;

	i = -1;
	if (ft_check_name(str))
	{
		len = ft_strlen(str);
		while (struct_env->env[++i])
		{
			if (!ft_strncmp(struct_env->env[i], str, len) && \
			struct_env->env[i][len] == '=')
			{
				struct_env->env = new_array_rm(struct_env->env, i);
				struct_env->keys = new_array_rm(struct_env->keys, i);
				struct_env->values = new_array_rm(struct_env->values, i);
				break ;
			}
		}
		if (!struct_env->env_lvl)
			return ;
		ft_unset_env_lvl(struct_env, str, len);
	}
}

int	ft_unset(t_command_and_flag	*all, t_env	*struct_env)
{
	int	num;

	num = 0;
	if (!all->array_flags[1])
		return (0);
	while (all->array_flags[++num])
	{
		if (all->array_flags[num][0] == '$')
			ft_unset_loop(&all->array_flags[num][1], struct_env);
		else
			ft_unset_loop(all->array_flags[num], struct_env);
	}
	return (0);
}
