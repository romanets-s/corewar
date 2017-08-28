/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:14:15 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 17:47:51 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			**ft_strsplit(char const *str, char c)
{
	int		i;
	int		n;
	int		z;
	char	**x;

	i = 0;
	n = 0;
	if (!str || ((x = malloc(sizeof(char*) * (splita(str, c) + 1))) == NULL))
		return (NULL);
	while (str[i])
	{
		while (str[i] && (char)str[i] == c)
			i++;
		if (str[i])
		{
			z = 0;
			if ((x[n] = malloc(sizeof(char) * splitd(str, i, c) + 1)) == NULL)
				return (NULL);
			while ((char)str[i] != c && str[i])
				x[n][z++] = (char)str[i++];
			x[n++][z] = '\0';
		}
	}
	x[n] = NULL;
	return (x);
}
