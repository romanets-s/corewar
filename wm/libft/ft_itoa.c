/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:31:37 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 17:49:32 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*itoa_minint(char *nb)
{
	nb[0] = '-';
	nb[1] = '2';
	nb[2] = '1';
	nb[3] = '4';
	nb[4] = '7';
	nb[5] = '4';
	nb[6] = '8';
	nb[7] = '3';
	nb[8] = '6';
	nb[9] = '4';
	nb[10] = '8';
	nb[11] = '\0';
	return (nb);
}

static void	itoa_itoyka(int *nbr, int *i, int *flag, int *znak)
{
	*i = 0;
	*flag = 0;
	*znak = 1;
	if (*nbr < 0)
	{
		*flag = 1;
		*nbr = *nbr * (-1);
	}
	*i = *nbr;
	while (*i >= 10)
	{
		*i = *i / 10;
		*znak = *znak + 1;
	}
	*i = 0;
}

static void	itoa_positive(char *nb, int *flag, int *i)
{
	if (*flag == 1)
	{
		nb[*i] = '-';
		*i = *i + 1;
	}
}

static void	itoa_calc(char *nb, int *nbr, int *div, int *i)
{
	while (*div != 0)
	{
		nb[*i] = *nbr / *div % 10 + '0';
		*div = *div / 10;
		*i = *i + 1;
	}
	nb[*i] = '\0';
}

char		*ft_itoa(int nbr)
{
	char	*nb;
	int		flag;
	int		znak;
	int		div;
	int		i;

	nb = NULL;
	if (nbr == -2147483648)
	{
		nb = (char*)malloc(12);
		return (itoa_minint(nb));
	}
	itoa_itoyka(&nbr, &i, &flag, &znak);
	nb = (char*)malloc(flag + znak + 1);
	if (!nb)
		return (0);
	itoa_positive(nb, &flag, &i);
	div = 1;
	while (znak > 1)
	{
		div = div * 10;
		znak--;
	}
	itoa_calc(nb, &nbr, &div, &i);
	return (nb);
}
