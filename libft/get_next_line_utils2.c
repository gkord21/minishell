/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:30:12 by iwhana21          #+#    #+#             */
/*   Updated: 2022/05/25 21:30:27 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	tern_oper(int read_count, char *ostatok, char *p_n)
{
	if (read_count == 0 && ft_strlen(ostatok) == 0 && p_n == NULL)
		return (1);
	return (0);
}

char	*lounch_strchar(char **p_n, char *buf)
{
	*p_n = ft_strchr(buf, '\n');
	return (*p_n);
}
