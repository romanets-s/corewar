/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_function_pack3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:48:04 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 12:48:05 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_vm_sti(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 25);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 2, 1);
	if (args[0][0] != T_REG || !args[0][1] ||
		!(args[0][2] == T_DIR || args[0][2] == T_REG))
	{
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	cw_load_reg(cw, c, args, 0);
	cw_load_reg(cw, c, args, 1);
	cw_load_ind(cw, c, args, 1);
	cw_load_reg(cw, c, args, 2);
	cw_put_inmem(cw, cw->ch[c].pc + args[1][1] + args[1][2], args[1][0]);
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}

void	cw_vm_fork(t_cw *cw, int c)
{
	unsigned int	where;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 800);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	where = cw_get_number(cw, cw->ch[c].pc + 1, cw->ch[c].pc + 1 + IND_SIZE);
	cw_cpy_ch(cw, c, where, 1);
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + 1 + IND_SIZE);
}

void	cw_vm_lld(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 10);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 4, 0);
	if (!(args[0][0] == T_DIR || args[0][0] == T_IND) ||
		args[0][1] != T_REG || args[0][2])
	{
		cw->ch[c].carry = false;
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	if (args[0][0] == T_IND)
		args[1][0] = cw_get_number(cw, args[1][0], args[1][0] + REG_SIZE);
	cw->ch[c].reg[args[1][1]] = args[1][0];
	cw->ch[c].carry = true;
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}

void	cw_vm_lldi(t_cw *cw, int c, int i)
{
	unsigned int	**args;

	if (is_pause(cw, c))
		return ;
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 2, 0);
	if (!args[0][0] || !(args[0][1] == T_DIR || args[0][1] == T_REG) ||
		args[0][2] != T_REG)
	{
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		cw->ch[c].carry = false;
		free_args(&(*args));
		return ;
	}
	while (++i < 2)
		cw_load_reg(cw, c, args, i);
	cw_load_ind(cw, c, args, 0);
	cw->ch[c].reg[args[1][2]] = cw_get_number(cw,
		cw->ch[c].pc + args[1][0] + args[1][1],
		cw->ch[c].pc + args[1][0] + args[1][1] + REG_SIZE);
	cw->ch[c].carry = true;
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}

void	cw_vm_lfork(t_cw *cw, int c)
{
	unsigned int	where;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 1000);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	where = cw_get_number(cw, cw->ch[c].pc + 1, cw->ch[c].pc + 1 + 2);
	cw_cpy_ch(cw, c, where, 0);
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + 1 + 2);
}
