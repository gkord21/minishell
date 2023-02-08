/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:56:52 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:44:25 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect(t_command_and_flag	*all, int	*fd1, int	*fd2)
{
	if (all->pape == MORE)
		*fd1 = open(all->command, O_WRONLY | O_TRUNC);
	else if (all->pape == DOUBLE_MORE)
		*fd1 = open(all->command, O_WRONLY | O_APPEND);
	else if (all->pape == LESS)
		*fd2 = open(all->command, O_RDONLY);
}

t_command_and_flag	*redirect2(t_command_and_flag	*all)
{
	int	fd;

	fd = 0;
	while (all && (all->pape == MORE || \
	all->pape == DOUBLE_MORE || all->pape == LESS))
	{
		if (all->pape == MORE)
		{
			fd = open(all->command, O_WRONLY | O_TRUNC);
			close(fd);
		}
		else if (all->pape == DOUBLE_MORE)
		{
			fd = open(all->command, O_WRONLY | O_APPEND);
			close(fd);
		}
		else if (all->pape == LESS)
		{
			fd = open(all->command, O_RDONLY);
			close(fd);
		}
		all = all->next;
	}
	return (all);
}
