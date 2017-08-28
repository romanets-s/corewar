/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:26:54 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/02/27 16:49:49 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static void	ft_lower(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'F')
			s[i] = s[i] + 32;
		i++;
	}
}

static void	ft_atoi_base_pars(char *str, int *nb, int *i, int base)
{
	while ((str[*i] >= '0' && str[*i] <= '9' && str[*i])
		|| (str[*i] >= 'a' && str[*i] <= 'f' && str[*i]))
	{
		if (str[*i] - 'a' >= 0)
			*nb = *nb * base + (str[(*i)++] - 'a' + 10);
		else
			*nb = *nb * base + str[(*i)++] - '0';
	}
}

int			ft_atoi_base(char *str, int base)
{
	int	i;
	int	flag;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && base == 10)
			flag = 1;
		i++;
	}
	ft_lower(str);
	if (base <= 10)
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			nb = nb * base + str[i++] - '0';
	else
		ft_atoi_base_pars(str, &nb, &i, base);
	if (flag == 1)
		nb = -nb;
	return (nb);
}
