/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:21:26 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/23 18:45:18 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(arr1 + i) != *(unsigned char *)(arr2 + i))
			return (*(unsigned char *)(arr1 + i)
				- *(unsigned char *)(arr2 + i));
		i++;
	}
	return (0);
}
