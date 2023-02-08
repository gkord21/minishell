/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:20:36 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:44:21 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	save_old_term(t_minishell *data)
{
	tcgetattr(fileno(stdin), &data->term->termios_und);
	return (0);
}

int	save_system_term(t_minishell *data)
{
	int				stat_1;
	struct termios	termios_p_in;

	stat_1 = tcgetattr(fileno(stdin), &termios_p_in);
	if (stat_1 == 0)
		data->term->termios_p_in = termios_p_in;
	else
		return (-1);
	return (0);
}

int	create_new_term(t_minishell *data)
{
	if (!isatty(fileno(stdin)))
		return (-1);
	data->term->term_name = getenv("TERM");
	if (data->term->term_name == NULL)
		data->term->term_name = "xterm-256color";
	data->term->termios_p_in.c_lflag &= ~(ICANON);
	data->term->termios_p_in.c_lflag &= ~(ECHO);
	data->term->termios_p_in.c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, &data->term->termios_p_in);
	tgetent(0, data->term->term_name);
	return (0);
}

int	handler_press(t_minishell *data, char **command, int *i, char **tmp)
{
	if (data->term->key == 0)
	{
		*tmp = *command;
		*command = ft_strjoin(*command, data->term->str);
		free(*tmp);
		write(1, data->term->str, data->term->len);
		*i = *i + data->term->len;
	}
	else
		data->term->key = 0;
	return (0);
}

char	*read_terminal(t_minishell *data)
{
	int				i;
	char			*command;
	char			*tmp;

	save_system_term(data);
	data->term->key = 0;
	save_old_term(data);
	create_char_command(&command);
	create_new_term(data);
	definition_history_line(data, &i);
	while (1 != 0)
	{
		data->term->len = read(0, data->term->str, 100);
		data->term->str[data->term->len] = '\0';
		arrow_handler(data, &command, &i, &tmp);
		handler_the_signals(data, &command, &i);
		if (data->term->key == 2)
			break ;
		handler_press(data, &command, &i, &tmp);
	}
	tcsetattr(fileno(stdin), TCSANOW, &(data->term->termios_und));
	free(data->term->str);
	return (command);
}
