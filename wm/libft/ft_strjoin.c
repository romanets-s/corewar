/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:52:22 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/23 20:51:13 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *tmp, char const *str)
{
	char	*fresh;
	char	*ptr;

	if ((fresh = (char*)malloc(ft_strlen((char*)tmp)
					+ ft_strlen((char*)str) + 1)) == NULL)
		return (NULL);
	ptr = fresh;
	if (tmp)
	{
		while (*tmp)
			*(fresh++) = *((char*)tmp++);
	}
	if (str)
	{
		while (*str)
			*(fresh++) = *((char*)str++);
	}
	*fresh = '\0';
	return (ptr);
}
