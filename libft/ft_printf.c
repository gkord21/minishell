/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalia <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:42:16 by amalia            #+#    #+#             */
/*   Updated: 2021/12/09 19:47:39 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int(int n, int *ptr_j, char c)
{
	if (c == 'c')
		ft_putchar1(n, ptr_j);
	else if (c == 'i' || c == 'd')
		ft_putnbr(n, ptr_j);
	return (2);
}

static int	ft_unsint(unsigned int un, int *ptr_j, char c)
{
	if (c == 'u')
		ft_putunsignednbr(un, ptr_j);
	else if (c == 'x')
		ft_putlowhexnbr(un, ptr_j);
	else if (c == 'X')
		ft_putuphexnbr(un, ptr_j);
	return (2);
}

static int	ft_void(void *ptr, int *ptr_j, char c)
{
	if (c == 's')
		ft_putstr((char *)ptr, ptr_j);
	else if (c == 'p')
		ft_putptr(ptr, ptr_j);
	return (2);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ptr;
	t_index	k;

	va_start(ptr, fmt);
	k.i = 0;
	k.j = 0;
	k.ptr_j = &k.j;
	while (fmt[k.i])
	{
		if (fmt[k.i] == '%' && (fmt[k.i + 1] == 'c' || fmt[k.i + 1] == 'i' \
		|| fmt[k.i + 1] == 'd'))
			k.i += ft_int(va_arg(ptr, int), k.ptr_j, fmt[k.i + 1]);
		else if (fmt[k.i] == '%' && fmt[k.i + 1] == '%')
			k.i += (ft_putchar1('%', k.ptr_j) + 1);
		else if (fmt[k.i] == '%' && (fmt[k.i + 1] == 's' \
		|| fmt[k.i + 1] == 'p'))
			k.i += ft_void(va_arg(ptr, void *), k.ptr_j, fmt[k.i + 1]);
		else if (fmt[k.i] == '%' && (fmt[k.i + 1] == 'u' || fmt[k.i + 1] == 'x' \
		|| fmt[k.i + 1] == 'X'))
			k.i += ft_unsint(va_arg(ptr, unsigned int), k.ptr_j, fmt[k.i + 1]);
		else
			k.i += ft_putchar1(fmt[k.i], k.ptr_j);
	}
	va_end(ptr);
	return (k.j);
}
