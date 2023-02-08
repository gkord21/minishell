/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:32:24 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/27 06:20:39 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;

	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	if (dest > src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[n - 1 - i]
				= ((unsigned char *)src)[n - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
