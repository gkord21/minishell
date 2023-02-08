/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:36:36 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:44:48 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	write_line_break(t_minishell *data)
{
	data->lvl--;
	write(1, "\n", 1);
	data->ret = 0;
	return (0);
}

char	**find_path(void)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	tmp = getenv("PATH");
	path = ft_split(tmp, ':');
	while (path[i])
	{
		tmp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(tmp);
		i++;
	}
	return (path);
}

int	create_loop(t_minishell *data, char *command, t_env *struct_env)
{
	while (1 != 0)
	{
		command = read_terminal(data);
		if (command == NULL)
		{
			write_line_break(data);
			break ;
		}
		if (command != NULL)
		{
			if (ft_strlen(command) != 0)
			{
				start_parser(data, struct_env, command);
				if (data->ret != -1)
					break ;
				free_path(data);
				find_path_from_new_env(data);
			}
			else
				free(command);
		}
	}
	return (0);
}

int	set_data(t_minishell *data, char **argv, t_env **struct_env, char **env)
{
	data->ret = -1;
	if (!argv[1])
		data->lvl = 0;
	else
		data->lvl = ft_atoi(argv[1]);
	*struct_env = allocate_env(env, data->lvl);
	create_env_lvl(*struct_env, data->lvl);
	data->flag = 1;
	data->env = *struct_env;
	data->path = find_path();
	data->single_q = 0;
	data->double_q = 0;
	data->head = NULL;
	crete_or_cheak_file_history(data, data->lvl);
	create_signal_controller();
	return (0);
}

int	start(int argc, char **argv, char **env)
{
	t_minishell			data;
	t_command_and_flag	command_and_flag;
	char				*command;
	t_term_sistem		term;
	t_env				*struct_env;

	command = NULL;
	(void)argc;
	data.term = &term;
	data.head = &command_and_flag;
	set_data(&data, argv, &struct_env, env);
	create_loop(&data, command, struct_env);
	free_path(&data);
	free_env(&data, data.env);
	ft_putstr_fd("exit\n", 0);
	return (data.ret);
}
