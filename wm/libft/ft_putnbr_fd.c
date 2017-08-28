/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:59:38 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/02 21:12:29 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	max_min_fd(int fd)
{
	ft_putstr_fd("-2147483648", fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		max_min_fd(fd);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
		if (nb < 10)
			ft_putchar_fd(nb + '0', fd);
	}
}
