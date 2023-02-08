/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_arrows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:33:13 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:44:05 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	press_up(t_minishell *data, char**command, int *i, char **tmp)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	if (data->term->history_slider != 0)
	{
		data->term->history_line = \
		reader_history_line(data, data->term->history_slider);
		write(1, data->term->history_line, \
		ft_strlen(data->term->history_line));
		data->term->history_slider--;
		free(*command);
		*command = (char *)malloc(sizeof(char) * 1);
		if (*command == NULL)
			return (-1);
		*command[0] = '\0';
		*tmp = *command;
		*command = ft_strjoin(*command, data->term->history_line);
		free(*tmp);
		free(data->term->history_line);
		*i = ft_strlen(*command);
	}
	return (0);
}

int	press_down(t_minishell *data, char **command, int *i, char **tmp)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	if (data->term->history_slider != MAX_LINE)
	{
		data->term->history_line = reader_history_line(data, \
		data->term->history_slider);
		write(1, data->term->history_line, \
		ft_strlen(data->term->history_line));
		data->term->history_slider++;
		free(*command);
		*command = (char *)malloc(sizeof(char) * 1);
		if (*command == NULL)
			return (0);
		*command[0] = '\0';
		*tmp = *command;
		*command = ft_strjoin(*command, data->term->history_line);
		free(*tmp);
		free(data->term->history_line);
		*i = ft_strlen(*command);
	}
	return (0);
}

int	arrow_handler(t_minishell *data,
			char **command, int *i, char **tmp)
{
	if (!ft_strcmp(data->term->str, "\e[A"))
	{
		press_up(data, command, i, tmp);
		data->term->key = 1;
	}
	else if (!ft_strcmp(data->term->str, "\e[B"))
	{
		press_down(data, command, i, tmp);
		data->term->key = 1;
	}
	else if (!ft_strcmp(data->term->str, "\e[C"))
	{
		data->term->key = 1;
	}
	else if (!ft_strcmp(data->term->str, "\e[D"))
	{
		data->term->key = 1;
	}
	return (0);
}
