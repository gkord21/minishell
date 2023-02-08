/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:38:56 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:43:44 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser_commands2(t_minishell *data)
{
	int					i;
	int					j;
	int					len;
	t_command_and_flag	*one_command;

	one_command = data->head;
	while (one_command)
	{
		skip_space(one_command, &i, &j, &len);
		while (one_command->command_and_flags[i])
		{
			parser_quotes(data, one_command, &i);
			if (one_command->command_and_flags[i] == ' ' && \
			data->single_q != 1 && data->double_q != 1)
				break ;
			i++;
		}
		fill_command(one_command, &i, &j, data);
		fill_flags(one_command, len, &i);
		one_command = one_command->next;
	}
	stat_command(data);
	parser_flags(data, data->head);
	return (0);
}

int	parser_commands(char *command, t_minishell *data)
{
	int		i;
	char	*new_command;
	int		j;

	i = 0;
	j = 0;
	data->pipe = NEW_COMMAND;
	shift_command(command, data);
	command = create_command_with_env_variables(command, data);
	data->single_q = 0;
	data->double_q = 0;
	while (command[i])
	{
		skip_slash(command, &i);
		parser_pipe(command, &i, &j, data);
		parser_redirection_out(command, &i, &j, data);
		parser_redirection_in(command, &i, &j, data);
		i++;
	}
	new_command = create_command(command, i, j, 1);
	create_list_command(new_command, data, data->pipe);
	parser_commands2(data);
	return (0);
}

int	start_parser(t_minishell *data, t_env *struct_env, char *command)
{
	parser_commands(command, data);
	free(command);
	data->ret = functions_launch(&data->head, \
			struct_env, &data->lvl, data);
	return (0);
}
