/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 07:18:26 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/21 07:18:30 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned char	*ft_ustrnew(size_t size)
{
	unsigned char	*tmp;
	unsigned char	*str;

	if ((tmp = (unsigned char*)malloc(size + 1)) == NULL)
		return (NULL);
	str = tmp;
	while (size--)
	{
		*str = 0;
		str++;
	}
	*str = '\0';
	return (tmp);
}
