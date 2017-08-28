/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:41:17 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 17:47:28 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	char	*str;
	char	*ptr;

	if (!s)
		return (NULL);
	str = (char*)s;
	if ((tmp = (char*)malloc(ft_strlen(str) + 1)) == NULL)
		return (NULL);
	ptr = tmp;
	while (*str)
	{
		*tmp = (*f)(*str);
		tmp++;
		str++;
	}
	*tmp = '\0';
	return (ptr);
}
