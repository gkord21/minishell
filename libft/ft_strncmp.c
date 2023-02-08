/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:04:10 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/26 19:53:01 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t	i;
	size_t	i1;

	i = 0;
	if (num < 1)
		return (0);
	while (num > 1 && *s1 == *s2 && *s1 && *s2)
	{
		num--;
		s1++;
		s2++;
	}
	i = *s1;
	i1 = *s2;
	if (i > i1)
		return (1);
	else if (i == i1)
		return (0);
	return (-1);
}
