/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:02:27 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:42:37 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_command_and_flag *all, int fd)
{
	int	i;

	i = 1;
	if (!all->array_flags[1])
	{	
		ft_putchar_fd('\n', fd);
		exit(0);
	}
	while (!ft_strncmp(all->array_flags[i], "-n", 3))
		i++;
	while (all->array_flags[i])
	{
		ft_putstr_fd(all->array_flags[i++], fd);
		if (all->array_flags[i])
			ft_putchar_fd(32, fd);
	}
	if (ft_strncmp(all->array_flags[1], "-n", 3))
		ft_putchar_fd('\n', fd);
	exit(0);
}
