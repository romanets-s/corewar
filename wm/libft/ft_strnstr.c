/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:03:33 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 18:29:48 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*a;
	int		i;

	b = (char*)little;
	if (*b == '\0')
		return ((char*)big);
	while (*big != '\0' && len != 0)
	{
		if (*big == *b)
		{
			a = (char*)big;
			i = 0;
			while ((*(b + i) == '\0' || *(a + i) == *(b + i)) &&
					(i++ <= (int)len))
				if (*(b + i - 1) == '\0')
					return ((char*)big);
			b = (char*)little;
		}
		big++;
		len--;
	}
	return (NULL);
}
