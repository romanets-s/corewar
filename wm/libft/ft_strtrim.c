/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:57:47 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 17:48:07 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_pustota(char const *s, int i)
{
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

static int		*ft_kakanol(int *kaka, char const *s)
{
	if (kaka[1] == 0 || kaka[2] == 0)
	{
		kaka[1] = 0;
		kaka[2] = ft_strlen((char*)s) - 1;
	}
	return (kaka);
}

static int		*ft_strtrimlen(char const *s, int *kaka)
{
	int		i;

	i = 0;
	kaka[0] = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	kaka[1] = i;
	while (s[i])
	{
		while ((s[i] != ' ' && s[i] != '\n' && s[i] != '\t') && s[i])
		{
			kaka[0]++;
			kaka[2] = i;
			i++;
		}
		if (ft_pustota(s, i) == 1)
			break ;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i++;
			kaka[0]++;
		}
	}
	kaka = ft_kakanol(kaka, s);
	return (&kaka[0]);
}

char			*ft_strtrim(char const *tmp)
{
	char	*fresh;
	int		*a;

	if (!tmp)
		return (NULL);
	if ((a = (int*)malloc(sizeof(int) * 3)) == NULL)
		return (NULL);
	a = ft_strtrimlen(tmp, a);
	if ((fresh = (char*)malloc(a[0] + 1)) == NULL)
		return (NULL);
	if (a[0] == 0)
	{
		fresh[0] = '\0';
		return (&fresh[0]);
	}
	a[0] = 0;
	while (a[1] <= a[2])
	{
		fresh[a[0]] = (char)tmp[a[1]];
		a[0]++;
		a[1]++;
	}
	fresh[a[0]] = '\0';
	return (&fresh[0]);
}
