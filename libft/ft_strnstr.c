/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:11:34 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/26 21:27:05 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i1;

	i1 = 0;
	i = 0;
	while (needle[i1])
		i1++;
	if (i1 == 0)
		return ((char *)haystack);
	while (len && *haystack)
	{
		while (*(haystack + i) == *(needle + i) && *(needle + i)
			&& (haystack + i) && (len - i))
			i++;
		if (i1 == i)
			return ((char *)(haystack));
		haystack++;
		len--;
		i = 0;
	}
	return (0);
}
