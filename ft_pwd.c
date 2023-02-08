/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:05:46 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:43:06 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **env, int fd)
{
	int		i;
	int		i1;
	char	buf[32000];

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
		{
			i1 = 3;
			while (env[i][++i1])
				ft_putchar_fd(env[i][i1], fd);
			ft_putchar_fd('\n', fd);
			exit(0);
		}
	}
	getcwd(buf, 32000);
	ft_putstr_fd(buf, fd);
	exit(0);
}
