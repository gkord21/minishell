/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:05:01 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:42:43 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_command_and_flag *all, char **env, int fd)
{
	int	i;

	i = -1;
	if (all->array_flags[1])
		exit(1);
	while (env[++i])
	{	
		ft_putstr_fd(env[i], fd);
		ft_putchar_fd('\n', fd);
	}
	exit(0);
}
