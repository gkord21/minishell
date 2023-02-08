/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalia <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:22:59 by amalia            #+#    #+#             */
/*   Updated: 2021/11/30 18:23:01 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexptr(unsigned long long int n, int *ptr_j)
{
	char	c;

	if (n >= 16)
	{
		ft_puthexptr(n / 16, ptr_j);
		ft_puthexptr(n % 16, ptr_j);
	}
	else
	{
		c = "0123456789abcdef"[n];
		ft_putchar1(c, ptr_j);
	}
}
