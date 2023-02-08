/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphexnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalia <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:24:31 by amalia            #+#    #+#             */
/*   Updated: 2021/11/30 18:24:35 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuphexnbr(unsigned int n, int *ptr_j)
{
	char	c;

	if (n >= 16)
	{
		ft_putuphexnbr(n / 16, ptr_j);
		ft_putuphexnbr(n % 16, ptr_j);
	}
	else
	{
		c = "0123456789ABCDEF"[n];
		ft_putchar1(c, ptr_j);
	}
}
