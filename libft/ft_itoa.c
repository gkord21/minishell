/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalia <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 04:21:59 by amalia            #+#    #+#             */
/*   Updated: 2021/10/26 20:21:12 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(int len, int m, unsigned int i, int n)
{
	char	*num;

	num = (char *)malloc(len + m + 1);
	if (!num)
		return (NULL);
	if (m == 1)
	{
		num[0] = '-';
		i = n * (-1);
	}
	else
		i = n;
	num[len + m] = '\0';
	n = len + m - 1;
	while (len)
	{
		num[n] = i % 10 + 48;
		i = i / 10;
		n--;
		len--;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	int				len;
	int				m;
	unsigned int	i;

	len = 1;
	m = 0;
	if (n < 0)
	{
		m = 1;
		i = n * (-1);
	}
	else
		i = n;
	while (i > 9)
	{
		i = i / 10;
		len++;
	}
	return (ft_strfill(len, m, i, n));
}
