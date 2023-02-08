/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:47:46 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:42:34 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd_change_pwd(char **env, char *buf)
{
	int		i;
	char	*tmp;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
		{
			tmp = env[i];
			env[i] = ft_strjoin("PWD=", buf);
			free(tmp);
			break ;
		}
	}
}

int	ft_cd(t_command_and_flag *all, char **env)
{
	int		i;
	char	buf[32000];
	char	*tmp;

	getcwd(buf, 32000);
	i = -1;
	if (chdir(all->array_flags[1]) == -1)
		return (10);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "OLDPWD=", 7))
		{
			tmp = env[i];
			env[i] = ft_strjoin("OLDPWD=", buf);
			free(tmp);
			break ;
		}
	}
	getcwd(buf, 32000);
	ft_cd_change_pwd(env, buf);
	return (0);
}
