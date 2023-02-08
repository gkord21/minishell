/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlowhexnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalia <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:23:47 by amalia            #+#    #+#             */
/*   Updated: 2021/11/30 18:23:50 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlowhexnbr(unsigned int n, int *ptr_j)
{
	char	c;

	if (n >= 16)
	{
		ft_putlowhexnbr(n / 16, ptr_j);
		ft_putlowhexnbr(n % 16, ptr_j);
	}
	else
	{
		c = "0123456789abcdef"[n];
		ft_putchar1(c, ptr_j);
	}
}
