/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalia <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:52:10 by amalia            #+#    #+#             */
/*   Updated: 2021/11/30 17:55:44 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int *ptr_j)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", ptr_j);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar1('-', ptr_j);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, ptr_j);
		ft_putnbr(n % 10, ptr_j);
	}
	else
		ft_putchar1(n + '0', ptr_j);
}
