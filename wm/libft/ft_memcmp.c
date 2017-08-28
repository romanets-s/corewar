/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:18:07 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 18:04:13 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)mem1 + i) != *((unsigned char*)mem2 + i))
			return (*((unsigned char*)mem1 + i) - *((unsigned char*)mem2 + i));
		i++;
	}
	return (0);
}
