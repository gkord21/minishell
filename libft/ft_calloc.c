/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:41:53 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/21 22:57:50 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;
	size_t	num2;

	if (num != 0 && size != 0)
	{
		if ((ssize_t)num < 0)
		{
			if (size != 1)
				return (NULL);
		}
		if ((ssize_t)size == -1)
		{
			if (num != 1)
				return (NULL);
		}
		num2 = num * size;
		if (num2 / size != num)
			return (NULL);
	}
	p = (void *)malloc(num * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, num * size);
	return (p);
}
