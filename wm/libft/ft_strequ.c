/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:26:50 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 18:10:02 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char	*temp;
	char	*str;

	if (!s1 || !s2)
		return (0);
	temp = (char*)s1;
	str = (char*)s2;
	while (*temp && *str)
	{
		if (*temp != *str)
			return (0);
		temp++;
		str++;
	}
	if (*temp == '\0' && *str == '\0')
		return (1);
	return (0);
}
