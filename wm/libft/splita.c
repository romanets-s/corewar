/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splita.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:25:38 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/03 18:32:15 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		splita(char const *str, char c)
{
	int	a;
	int	flag;
	int	kilkist;

	a = 0;
	flag = 0;
	kilkist = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		while ((char)str[a] != c && str[a])
		{
			a++;
			flag = 1;
		}
		if ((char)str[a] == c || (char)str[a] == '\0')
		{
			kilkist += (flag == 1) ? 1 : 0;
			flag = 0;
			a++;
		}
	}
	return (kilkist);
}
