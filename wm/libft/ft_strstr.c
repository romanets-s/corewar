/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 20:28:16 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 18:30:25 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char *b;
	char *a;

	b = (char*)to_find;
	if (*b == '\0')
		return ((char*)str);
	while (*str != '\0')
	{
		if ((char)(*str) == *b)
		{
			a = (char*)str;
			while (*a == *b || *b == '\0')
			{
				if (*b == '\0')
					return ((char*)str);
				a++;
				b++;
			}
			b = (char*)to_find;
		}
		str++;
	}
	return (0);
}
