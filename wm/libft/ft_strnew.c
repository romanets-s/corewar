/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:03:43 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 18:23:36 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *tmp;
	char *str;

	if ((tmp = (char*)malloc(size + 1)) == NULL)
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
