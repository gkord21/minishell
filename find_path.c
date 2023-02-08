/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:37:37 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:42:26 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_path_from_new_env_utils(t_minishell *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->path[i])
	{
		tmp = data->path[i];
		data->path[i] = ft_strjoin(data->path[i], "/");
		free(tmp);
		i++;
	}
	return (0);
}

int	find_path_from_new_env(t_minishell *data)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (data->env->keys[i])
	{
		if (ft_strnstr(data->env->keys[i], "PATH", \
				ft_strlen(data->env->keys[i])))
		{
			path = ft_strdup(data->env->values[i]);
			data->path = ft_split(path, ':');
			find_path_from_new_env_utils(data);
			break ;
		}
		i++;
	}
	if (path == NULL)
		data->path = NULL;
	else
		free(path);
	return (0);
}
