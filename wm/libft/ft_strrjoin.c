/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:20:17 by irepeta           #+#    #+#             */
/*   Updated: 2017/06/27 19:22:42 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			*ft_strrjoin(char *tmp, char *str)
{
	char	*fresh;
	char	*ptr;
	char	*jopa;

	if ((fresh = (char*)malloc(ft_strlen((char*)tmp)
				+ ft_strlen((char*)str) + 1)) == NULL)
		return (NULL);
	ptr = fresh;
	jopa = tmp;
	if (tmp)
	{
		while (*tmp)
			*(fresh++) = *((char *)tmp++);
		free(jopa);
		tmp = NULL;
	}
	if (str)
	{
		while (*str)
			*(fresh++) = *((char*)str++);
	}
	*fresh = '\0';
	return (ptr);
}
