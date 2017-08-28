/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:06:52 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 18:04:23 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	unsigned char	*d;
	unsigned char	*s;

	d = destptr;
	s = (void*)srcptr;
	while (num != 0)
	{
		*d = *s;
		d++;
		s++;
		num--;
	}
	return (destptr);
}
