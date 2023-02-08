/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:37:32 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/27 07:20:58 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == (char)ch)
			ptr = (char *)str;
		str++;
	}
	if (ch == 0)
		return ((char *)str);
	return (ptr);
}
