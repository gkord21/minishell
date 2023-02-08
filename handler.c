/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:58:02 by iwhana21          #+#    #+#             */
/*   Updated: 2022/06/04 04:43:16 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handler_the_shooter2(t_minishell *data)
{
	if (!ft_strcmp(data->term->str, "\e[A"))
	{
	}
	else if (!ft_strcmp(data->term->str, "\e[B"))
	{
	}
	else if (!ft_strcmp(data->term->str, "\e[C"))
	{
	}
	else if (!ft_strcmp(data->term->str, "\e[D"))
	{
	}
	return (0);
}

int	handler_the_signals(t_minishell *data,
		char **command, int *i)
{
	if (!ft_strcmp(data->term->str, "\177"))
	{
		press_backspase(i, command);
		data->term->key = 1;
	}
	else if (!ft_strcmp(data->term->str, "\n"))
	{
		write(1, "\n", 1);
		data->term->key = 2;
	}
	else if (!ft_strcmp(data->term->str, "\4"))
	{
		if (ft_strlen(*command) == 0)
		{
			free(*command);
			*command = NULL;
			data->term->key = 2;
		}
	}
	else if (!ft_strcmp(data->term->str, "\3"))
	{
		press_control_c(command);
		data->term->key = 2;
	}
	return (0);
}
