/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:22:26 by iwhana            #+#    #+#             */
/*   Updated: 2021/10/26 20:35:02 by amalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	char			*nb;
	unsigned char	new;

	nb = buf;
	new = (unsigned char)ch;
	while (count--)
	{
		*nb++ = new;
	}
	return (buf);
}
