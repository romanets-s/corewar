/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 18:15:48 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 18:27:33 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char			*d;
	size_t			i;
	int				flag;

	flag = 0;
	d = dest;
	i = 0;
	while (i < n)
	{
		if (*src == '\0' || flag == 1)
		{
			*d = '\0';
			flag = 1;
		}
		if (flag == 0)
			*d = *src;
		d++;
		src++;
		i++;
	}
	return (dest);
}
