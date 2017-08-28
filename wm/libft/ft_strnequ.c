/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:35:49 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/03 14:27:53 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*temp;
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	temp = (char*)s1;
	str = (char*)s2;
	while (temp[i] && str[i] && i < (int)n)
	{
		if (temp[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}
