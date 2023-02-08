/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_launch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:38:36 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:43:12 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_launch(t_env *struct_env, int size, t_command_and_flag *tmp)
{
	if (!ft_strncmp(tmp->command, "export", 7) && size == 0)
	{
		ft_export(tmp, 0, struct_env);
		export_errors(tmp, struct_env);
		return (0);
	}
	else if (!ft_strncmp(tmp->command, "unset", 6) && size == 0)
	{
		ft_unset(tmp, struct_env);
		export_errors(tmp, struct_env);
		return (0);
	}
	else if (size == 0 && !ft_strncmp(tmp->command, "cd", 3))
	{	
		if (ft_cd(tmp, struct_env->env) == 10)
		{	
			ft_putstr_fd("cd: no such file or directory: ", 0);
			if (tmp->array_flags[1])
				ft_putstr_fd(tmp->array_flags[1], 0);
			ft_putstr_fd("\n", 0);
		}
		return (0);
	}
	return (1);
}

void	ft_minishell_name(int *lvl, t_env *struct_env)
{
	char	**argv;
	char	*tmp_2;
	int		i;

	i = 0;
	(*lvl)++;
	argv = (char **)malloc(sizeof(char *) * 3);
	if (!argv)
		return ;
	argv[0] = ft_strdup("a.out");
	tmp_2 = ft_itoa(*(lvl));
	argv[1] = ft_strdup(tmp_2);
	free(tmp_2);
	argv[2] = 0;
	struct_env->exit_num = start(2, argv, struct_env->env);
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

int	functions_launch(t_command_and_flag	**head,	\
t_env	*struct_env, int	*lvl, t_minishell *all)
{
	t_command_and_flag	*current_head;
	t_command_and_flag	*tmp;
	int					size;
	int					ret;

	ret = -1;
	tmp = 0;
	current_head = *head;
	size = 0;
	number_of_pipes(&size, &current_head, &tmp, all);
	if (builtin_launch(struct_env, size, tmp))
	{
		if ((!ft_strncmp(tmp->command, "exit", 5) || \
		!ft_strncmp(current_head->command, "exit", 5)) && size == 0)
			ret = ft_exit(tmp, struct_env);
		else if (size >= 0)
			find_function(size, struct_env, tmp, *head);
	}
	ft_list_clear(tmp);
	if (!ft_strncmp(current_head->command, "minishell", 10))
		ft_minishell_name(lvl, struct_env);
	return (ret);
}
