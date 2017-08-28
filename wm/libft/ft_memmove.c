/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:13:45 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/02 14:32:21 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;

	if ((dest - src) >= 0)
	{
		i = n;
		while (--i != -1)
			*((unsigned char*)dest + i) = *((unsigned char*)src + i);
	}
	else
	{
		i = 0;
		while ((size_t)i < n)
		{
			*((unsigned char*)dest + i) = *((unsigned char*)src + i);
			i++;
		}
	}
	return (dest);
}
