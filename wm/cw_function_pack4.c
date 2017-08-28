/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_function_pack4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:48:10 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 12:48:13 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_vm_aff(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 2);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	if (cw->visual)
		return ;
	args = cw_get_arg(cw, c, 2, 0);
	if (args[0][0] != T_REG || args[0][1] || args[0][2])
	{
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(args);
		return ;
	}
	ft_putchar((char)(cw->ch[c].reg[args[1][0]] % 256));
	ft_putchar('\n');
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
}

void	cw_vm_next(t_cw *cw, int c)
{
	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 1);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + 1);
}

void	free_args(unsigned int **args)
{
	free(args[0]);
	free(args[1]);
	free(args);
}

int		is_pause(t_cw *cw, int c)
{
	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 50);
		return (1);
	}
	return (0);
}
