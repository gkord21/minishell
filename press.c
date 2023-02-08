/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:59:50 by iwhana21          #+#    #+#             */
/*   Updated: 2022/06/04 04:44:08 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	press_backspase(int *i, char **command)
{
	if (*i != 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		(*command)[ft_strlen(*command) - 1] = '\0';
		*i = *i - 1;
	}
	return (0);
}

int	press_control_c(char **command)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tgetstr("ed", 0), 1, ft_putchar);
	write(1, "\n", 1);
	free(*command);
	*command = malloc(sizeof(char) * 1);
	if (*command == NULL)
		return (0);
	*command[0] = '\0';
	return (0);
}
