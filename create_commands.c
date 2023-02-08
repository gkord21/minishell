/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:16:39 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:41:33 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_char_command(char **command)
{
	*command = (char *)malloc(sizeof(char) * 1);
	if (*command == NULL)
		return (0);
	*command[0] = '\0';
	return (0);
}

char	*create_command(char *command, int i, int j, int key)
{
	char	*new_command;
	int		k;

	k = 0;
	new_command = (char *)malloc(sizeof(char) * (i - j + 1));
	if (new_command == NULL)
		return (NULL);
	while (k < (i - j))
	{
		new_command[k] = command[j + k];
		if (command[j + k] == '"' && key == 0)
			break ;
		k++;
	}
	new_command[k] = '\0';
	return (new_command);
}
