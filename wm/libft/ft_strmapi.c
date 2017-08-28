/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:21:29 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 17:47:37 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	char	*str;
	char	*ptr;
	int		i;

	if (!s)
		return (NULL);
	str = (char*)s;
	i = 0;
	if ((tmp = (char*)malloc(ft_strlen(str) + 1)) == NULL)
		return (NULL);
	ptr = tmp;
	while (str[i])
	{
		tmp[i] = (*f)(i, str[i]);
		i++;
	}
	tmp[i] = '\0';
	return (ptr);
}
