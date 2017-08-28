/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:45:54 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/03 13:17:10 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*tmp;
	const char	*ss;
	size_t		i;
	size_t		len;

	tmp = dest;
	ss = src;
	i = size;
	while (*tmp != '\0' && i-- != 0)
		tmp++;
	len = tmp - dest;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(ss));
	while (*ss)
	{
		if (i != 1)
		{
			*tmp++ = *ss;
			i--;
		}
		ss++;
	}
	*tmp = '\0';
	return (len + (ss - src));
}
