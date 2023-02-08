/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 02:08:15 by iwhana21          #+#    #+#             */
/*   Updated: 2022/06/04 04:43:26 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	if (!argv[1])
		return (start(argc, argv, env));
	else
		ft_putstr_fd("Error:too many arguments\n", 0);
	return (0);
}
