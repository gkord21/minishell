/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:59:29 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:47:32 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exit_num(char	*str)
{
	if (ft_strlen(str) > 10)
	{
		ft_putstr_fd("minishell: exit:", 0);
		ft_putstr_fd(str, 0);
		ft_putstr_fd(": numeric argument required\n", 0);
		return (1);
	}
	return (0);
}

int	exit_error(t_command_and_flag *reverse_head, t_env *env)
{
	if (!ft_strncmp(reverse_head->command, "exit", 5))
	{
		if (reverse_head->array_flags[1])
		{
			if (check_exit_num(reverse_head->array_flags[1]))
			{
				env->exit_num = 255;
				return (0);
			}
		}
	}
	return (1);
}

int	ft_exit(t_command_and_flag	*tmp, t_env *env)
{
	long long	ret;

	if (tmp->array_flags[1])
	{
		if (check_exit_num(tmp->array_flags[1]) == 1)
		{
			env->exit_num = 255;
			return (-1);
		}
		if (ft_atoi(tmp->array_flags[1]) > 0)
			ret = ft_atoi(tmp->array_flags[1]) % 256;
		else
		{
			ret = ft_atoi(tmp->array_flags[1]);
			while (ret < 0)
				ret = 256 + ret;
		}
	}
	else
		ret = 0;
	return ((int)ret);
}
