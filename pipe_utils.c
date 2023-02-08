/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:14:37 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:44:00 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_pipe(int *pipe, int where)
{
	if (pipe != 0)
	{
		dup2(pipe[where], where);
		close(pipe[1]);
		close(pipe[0]);
	}
}

void	redirect_fd(int fd, int where)
{
	if (fd)
	{
		dup2(fd, where);
		close(fd);
	}
}

void	close_pipe(int	*pipe)
{
	if (pipe != 0)
	{
		close(pipe[1]);
		close(pipe[0]);
	}
}
