/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:44:03 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:43:02 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_no_arguments(char **env, char **env_lvl, int fd)
{
	int	i;
	int	i1;

	i = -1;
	while (env[++i])
	{
		i1 = 0;
		ft_putstr_fd("declare -x ", fd);
		while (env[i][i1] && env[i][i1] != '=')
			ft_putchar_fd(env[i][i1++], fd);
		ft_putchar_fd(env[i][i1], fd);
		ft_putchar_fd(34, fd);
		while (env[i][++i1])
			ft_putchar_fd(env[i][i1], fd);
		ft_putchar_fd(34, fd);
		ft_putchar_fd('\n', fd);
	}
	i = -1;
	while (env_lvl && env_lvl[++i])
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(env_lvl[i], fd);
		ft_putchar_fd('\n', fd);
	}
}

void	ft_export_loop(char *str, t_env *struct_env)
{
	int		end_of_key;
	int		value;

	end_of_key = 0;
	ft_value_name(str, &end_of_key, &value);
	if (!ft_check_env(struct_env, str, end_of_key, value))
		return ;
	if (!ft_check_env_lvl(struct_env, str, end_of_key, value))
		return ;
	if (!value)
		struct_env->env_lvl = new_array_add(struct_env->env_lvl, str);
	else
	{
		str[end_of_key] = '\0';
		struct_env->keys = new_array_add(struct_env->keys, str);
		struct_env->values = new_array_add(struct_env->values, \
		&str[end_of_key + 1]);
		str[end_of_key] = '=';
		struct_env->env = new_array_add(struct_env->env, str);
	}
}

int	ft_export(t_command_and_flag *all, int fd, t_env *struct_env)
{
	int	i;

	i = 1;
	if (!all->array_flags[1])
		ft_export_no_arguments(struct_env->env, struct_env->env_lvl, fd);
	else
	{
		while (all->array_flags[i])
		{	
			if (ft_check_name(all->array_flags[i]))
				ft_export_loop(all->array_flags[i], struct_env);
			i++;
		}
	}
	if (fd)
		close(fd);
	return (0);
}
