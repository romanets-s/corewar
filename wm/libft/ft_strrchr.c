/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:50:24 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 17:36:19 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	int	i;

	i = ft_strlen(str);
	while (*str)
		str++;
	while (i >= 0)
	{
		if (*str == (char)symbol)
			return ((char*)str);
		str--;
		i--;
	}
	if ((char)symbol == '\0' && *str == '\0')
		return ((char*)str);
	return (NULL);
}
