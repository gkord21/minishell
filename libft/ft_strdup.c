/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:32:30 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/26 20:42:49 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;
	size_t	i1;

	i1 = 0;
	i = ft_strlen((char *)s1);
	s2 = (char *)malloc(i + 1);
	if (!s2)
		return (NULL);
	while (i >= i1)
	{
		s2[i1] = s1[i1];
		i1++;
	}
	return (s2);
}
