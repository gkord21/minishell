/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:26:44 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:44:37 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_manager(int sig)
{
	if (g_global_pid != 0 && sig == SIGINT)
	{
		kill(g_global_pid, sig);
		write(1, "\n", 1);
		g_global_pid = 0;
	}
	if (g_global_pid != 0 && sig == SIGQUIT)
	{
		kill(g_global_pid, sig);
		write(1, "Quit: 3\n", 8);
		g_global_pid = 0;
	}
}

void	create_signal_controller(void)
{
	signal(SIGINT, &signal_manager);
	signal(SIGQUIT, &signal_manager);
	g_global_pid = 0;
}
