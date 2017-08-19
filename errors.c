/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 20:49:31 by sromanet          #+#    #+#             */
/*   Updated: 2017/08/17 20:49:34 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error2(t_asm *bin, int error)
{
	int k;
	int n;
	int a;

	n = 0;
	k = 1;
	a = bin->i;
	if (error <= 0 && error >= 10)
	{
		while (a > -1)
			if (bin->file[a--] == '\n')
				k++;
		while (bin->file[bin->i--] != '\n')
			n++;
		ft_printf("Syntax error at token [%03d:%03d]\n", k, n);
	}
	exit(0);
}

void	error(t_asm *bin, int r, int error)
{
	if (error == 1)
		ft_printf("Syntax error in Name\n");
	else if (error == 2)
		ft_printf("Syntax error in Comment\n");
	else if (error == 3)
		ft_printf("No Name\n");
	else if (error == 4)
		ft_printf("No Comment\n");
	else if (error == 5)
		ft_printf("Syntax error - unexpected end of input"
				"(Perhaps you forgot to end with a newline ?)\n");
	else if (error == 6)
		ft_printf("Invalid parametr for instruction '%s'\n", bin->op[r].name);
	else if (error == 7)
	{
		ft_printf("No such label ");
		write(1, bin->ptr, ft_strlen(bin->ptr));
		ft_printf("\n");
	}
	else if (error == 8)
		ft_printf("Syntax error at token [TOKEN][001:001] END '(null)'\n");
	else if (error == 9)
		ft_printf("Use file .s\n");
	error2(bin, error);
}
