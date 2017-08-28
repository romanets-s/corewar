/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:04:18 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 18:07:40 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *ptr, int symbol)
{
	unsigned char *str;

	str = (unsigned char*)ptr;
	while (*str)
	{
		if (*str == (unsigned char)symbol)
			return ((char*)str);
		str++;
	}
	if ((char)symbol == '\0' && *str == '\0')
		return ((char*)str);
	return (NULL);
}
