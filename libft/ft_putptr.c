/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalia <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:21:46 by amalia            #+#    #+#             */
/*   Updated: 2021/11/30 18:21:50 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(void *ptr, int *ptr_j)
{
	unsigned long long int	n;

	n = (unsigned long long int) ptr;
	ft_putchar1('0', ptr_j);
	ft_putchar1('x', ptr_j);
	ft_puthexptr(n, ptr_j);
}
