/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:41:37 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 14:41:42 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

char			*cw_int_decrypt(unsigned char c)
{
	int		a;
	int		b;
	char	*str;

	a = c / 0x10;
	b = c % 0x10;
	str = ft_strnew(8);
	str[0] = (a / 8) % 2;
	str[1] = (a >> 2) % 2;
	str[2] = (a / 2) % 2;
	str[3] = a % 2;
	str[4] = (b / 8) % 2;
	str[5] = (b >> 2) % 2;
	str[6] = (b / 2) % 2;
	str[7] = b % 2;
	return (str);
}

unsigned int	cw_real_ptr(unsigned int s)
{
	if (s < MEM_SIZE)
		return (s);
	return (s % MEM_SIZE);
}

unsigned int	cw_get_number(t_cw *cw, unsigned int s, unsigned int e)
{
	unsigned int	num;
	unsigned int	base;

	base = 1;
	num = 0;
	--e;
	while (e > s - 1)
	{
		num += (cw->vm.mem[cw_real_ptr(e)] % 16) * base;
		base *= 16;
		num += (cw->vm.mem[cw_real_ptr(e)] >> 4) * base;
		base *= 16;
		--e;
	}
	return (num);
}
