/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:06:58 by iwhana21          #+#    #+#             */
/*   Updated: 2022/06/04 04:44:54 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_list_push_front(t_command_and_flag	**begin_list, \
	t_command_and_flag	*data)
{
	t_command_and_flag	*elem;

	if (begin_list != 0)
	{
		elem = ft_create_elem(data);
		elem->next = *begin_list;
		*begin_list = elem;
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_list_push_second(t_command_and_flag	**begin_list, \
	t_command_and_flag	*data)
{
	t_command_and_flag	*elem1;
	t_command_and_flag	*tmp;

	elem1 = *begin_list;
	if (*begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
	{
		tmp = elem1->next;
		elem1->next = ft_create_elem(data);
		elem1->next->next = tmp;
	}
}

char	*my_getenv(char *name_env, t_minishell *data)
{
	int	i;

	i = 0;
	if (name_env[0] == '?')
		return (NULL);
	while (data->env->keys[i])
	{
		if (!ft_strncmp(data->env->keys[i], name_env, \
		ft_strlen(name_env)) && \
		ft_strlen(data->env->keys[i]) == ft_strlen(name_env))
			break ;
		i++;
	}
	return (data->env->values[i]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	a;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	a = *(const unsigned char *)s1 - *(const unsigned char *)s2;
	return (a);
}
