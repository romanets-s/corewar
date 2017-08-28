/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:23:00 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/23 20:47:00 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned char	*ft_ustrdup(const unsigned char *src)
{
	unsigned char	*dest;
	unsigned char	*ptr;
	size_t			len;

	if (src)
		len = ft_ustrlen(src);
	else
		len = 0;
	if ((dest = (unsigned char*)malloc(sizeof(*dest) * (len + 1))) == NULL)
		return (NULL);
	ptr = dest;
	if (src)
	{
		while (*src != '\0')
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
	*dest = '\0';
	return (ptr);
}
