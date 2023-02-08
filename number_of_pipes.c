/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:24:36 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:43:30 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*term_from_double_less(t_minishell *data)
{
	int				i;
	char			*command;
	char			*tmp;

	data->term->key = 0;
	save_old_term(data);
	create_char_command(&command);
	create_new_term(data);
	definition_history_line2(data, &i);
	while (1 != 0)
	{
		data->term->len = read(0, data->term->str, 100);
		data->term->str[data->term->len] = '\0';
		handler_the_shooter2(data);
		handler_the_signals(data, &command, &i);
		if (data->term->key == 2)
			break ;
		handler_press(data, &command, &i, &tmp);
	}
	tcsetattr(fileno(stdin), TCSANOW, &(data->term->termios_und));
	free(data->term->str);
	return (command);
}

t_command_and_flag	*ft_double_less(char	*split, t_minishell *all_com)
{
	char				*str;
	int					len;
	t_command_and_flag	*all;

	all = malloc(sizeof(t_command_and_flag));
	if (!all)
		return (0);
	all->command = ft_strdup(split);
	all->array_flags = 0;
	all->array_flags = new_array_add(all->array_flags, split);
	len = ft_strlen(split);
	while (1)
	{
		str = term_from_double_less(all_com);
		if (str == NULL)
			break ;
		if (!ft_strncmp(str, split, len + 1))
			break ;
		all->array_flags = new_array_add(all->array_flags, str);
		free(str);
	}
	all->pape = DOUBLE_LESS;
	free(str);
	return (all);
}

void	number_of_pipes(int	*size, t_command_and_flag	**head1, \
t_command_and_flag	**new_head, t_minishell *all)
{
	t_command_and_flag	*head;
	t_command_and_flag	*tmp;

	tmp = 0;
	head = *head1;
	*size = 0;
	if (head->pape == MORE || head->pape == DOUBLE_MORE)
		*size = -1;
	ft_list_push_front(new_head, head);
	head = head->next;
	while (head)
	{
		if (head->pape != MORE && head->pape != \
		DOUBLE_MORE && head->pape != LESS)
			*size += 1;
		if (head->pape == DOUBLE_LESS)
		{
			tmp = ft_double_less(head->command, all);
			ft_list_push_second(new_head, tmp);
			free_tmp(tmp);
		}
		else
			ft_list_push_front(new_head, head);
		head = head->next;
	}
}
