/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalia <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:25:12 by amalia            #+#    #+#             */
/*   Updated: 2021/11/30 18:25:14 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsignednbr(unsigned int n, int *ptr_j)
{
	if (n >= 10)
	{
		ft_putunsignednbr(n / 10, ptr_j);
		ft_putunsignednbr(n % 10, ptr_j);
	}
	else
		ft_putchar1(n + '0', ptr_j);
}
