/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:51:52 by iwhana            #+#    #+#             */
/*   Updated: 2021/11/02 20:16:21 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		dest = malloc(sizeof(char) * (len + 1));
		if (dest == NULL)
			return (NULL);
		i = 0;
		while (++i - 1 < len)
			*(dest + i - 1) = *(s + start + i - 1);
		*(dest + i - 1) = '\0';
		return (dest);
	}
	return (NULL);
}
