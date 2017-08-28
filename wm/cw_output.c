/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:45:31 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 14:45:36 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_output(t_cw *cw)
{
	int		i;
	char	*tab;

	tab = "0123456789abcdef\0";
	i = 0;
	while (i < MEM_SIZE)
	{
		while ((i + 1) % VM_MEM_INLINE != 0)
		{
			if (i % VM_MEM_INLINE)
				ft_putchar(' ');
			ft_putchar(*(tab + (cw->vm.mem[i] >> 4)));
			ft_putchar(*(tab + (cw->vm.mem[i] % 16)));
			i++;
		}
		ft_putchar(' ');
		ft_putchar(*(tab + (cw->vm.mem[i] >> 4)));
		ft_putchar(*(tab + (cw->vm.mem[i] % 16)));
		ft_putstr("\n");
		i++;
	}
}
