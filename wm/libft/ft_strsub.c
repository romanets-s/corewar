/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:43:37 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 17:47:59 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	char	*str;
	char	*ptr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char*)s;
	if ((tmp = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	ptr = tmp;
	while (i < (int)len)
	{
		tmp[i] = str[start];
		start++;
		i++;
	}
	tmp[i] = '\0';
	return (ptr);
}
