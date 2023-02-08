/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:33:23 by iwhana            #+#    #+#             */
/*   Updated: 2022/04/08 01:49:01 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict str1, const char *restrict str2)
{
	char	*tmp;

	tmp = str1;
	while (*str1)
		str1++;
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (tmp);
}
