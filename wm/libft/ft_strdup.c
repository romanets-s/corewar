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

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*ptr;
	size_t	len;

	if (src)
		len = ft_strlen(src);
	else
		len = 0;
	if ((dest = (char*)malloc(sizeof(*dest) * (len + 1))) == NULL)
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
