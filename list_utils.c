/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:39:35 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:43:20 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command_and_flag	*ft_lstnew(char *command, int pape)
{
	t_command_and_flag	*new_list;

	new_list = (t_command_and_flag *)malloc(sizeof(t_command_and_flag));
	if (new_list == NULL)
		return (NULL);
	new_list->command_and_flags = command;
	new_list->command = NULL;
	new_list->pape = pape;
	new_list->flags = NULL;
	new_list->num_proc = 0;
	new_list->array_flags = NULL;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back(t_command_and_flag **lst, t_command_and_flag *new)
{
	t_command_and_flag	*a;

	a = *lst;
	if (!*lst && new)
	{
		*lst = new;
	}
	while (a)
	{
		if (a->next == NULL)
		{
			a->next = new;
			break ;
		}
		else
			a = a->next;
	}
}

int	create_list_command(char *command, t_minishell *data, int pipe)
{
	t_command_and_flag	*new_command;

	new_command = ft_lstnew(command, pipe);
	ft_lstadd_back(&data->head, new_command);
	return (0);
}

void	ft_list_clear(t_command_and_flag *command)
{
	int					i;
	t_command_and_flag	*tmp;

	while (command)
	{
		free(command->command);
		i = 0;
		while (command->array_flags[i])
		{
			free(command->array_flags[i]);
			i++;
		}
		free(command->array_flags);
		tmp = command->next;
		free(command);
		command = tmp;
	}
}

t_command_and_flag	*ft_create_elem(t_command_and_flag *data)
{
	t_command_and_flag	*elem;
	int					i;

	i = 0;
	elem = (t_command_and_flag *)malloc(sizeof(t_command_and_flag));
	if (elem == NULL)
		return (NULL);
	elem->pape = data->pape;
	elem->command = ft_strdup(data->command);
	while (data->array_flags[i])
		i++;
	elem->array_flags = malloc(sizeof(char *) * (i + 1));
	if (!elem->array_flags)
		return (0);
	i = -1;
	while (data->array_flags[++i])
		elem->array_flags[i] = ft_strdup(data->array_flags[i]);
	elem->array_flags[i] = NULL;
	elem->next = 0;
	return (elem);
}
