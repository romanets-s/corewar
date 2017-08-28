/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_function_pack2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:47:57 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 12:47:59 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_vm_and(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 6);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 4, 1);
	if (!args[0][0] || !args[0][1] || args[0][2] != T_REG)
	{
		cw->ch[c].carry = false;
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	cw_load_reg(cw, c, args, 0);
	cw_load_ind(cw, c, args, 0);
	cw_load_reg(cw, c, args, 1);
	cw_load_ind(cw, c, args, 1);
	cw->ch[c].reg[args[1][2]] = args[1][0] & args[1][1];
	cw->ch[c].carry = true;
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}

void	cw_vm_or(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 6);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 4, 1);
	if (!args[0][0] || !args[0][1] || args[0][2] != T_REG)
	{
		cw->ch[c].carry = false;
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	cw_load_reg(cw, c, args, 0);
	cw_load_ind(cw, c, args, 0);
	cw_load_reg(cw, c, args, 1);
	cw_load_ind(cw, c, args, 1);
	cw->ch[c].reg[args[1][2]] = args[1][0] | args[1][1];
	cw->ch[c].carry = true;
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}

void	cw_vm_xor(t_cw *cw, int c)
{
	unsigned int	**args;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 6);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	args = cw_get_arg(cw, c, 4, 1);
	if (!args[0][0] || !args[0][1] || args[0][2] != T_REG)
	{
		cw->ch[c].carry = false;
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	cw_load_reg(cw, c, args, 0);
	cw_load_ind(cw, c, args, 0);
	cw_load_reg(cw, c, args, 1);
	cw_load_ind(cw, c, args, 1);
	cw->ch[c].reg[args[1][2]] = args[1][0] ^ args[1][1];
	cw->ch[c].carry = true;
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}

void	cw_vm_zjmp(t_cw *cw, int c)
{
	unsigned int	where;

	if (!cw->ch[c].cpause)
	{
		cw_set_pause(cw, c, 20);
		return ;
	}
	else
		cw->ch[c].cpause = false;
	where = cw_get_number(cw, cw->ch[c].pc + 1, cw->ch[c].pc + 1 + IND_SIZE);
	if (cw->ch[c].carry)
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + (where % IDX_MOD));
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + 1 + IND_SIZE);
}

void	cw_vm_ldi(t_cw *cw, int c)
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
	if (!args[0][0] || !(args[0][1] == T_DIR || args[0][1] == T_REG) ||
		args[0][2] != T_REG)
	{
		cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
		free_args(&(*args));
		return ;
	}
	cw_load_reg(cw, c, args, 0);
	cw_load_ind(cw, c, args, 0);
	cw_load_reg(cw, c, args, 1);
	cw->ch[c].reg[args[1][2]] = cw_get_number(cw,
		cw->ch[c].pc + (args[1][0] + args[1][1]) % IDX_MOD,
		cw->ch[c].pc + (args[1][0] + args[1][1]) % IDX_MOD + REG_SIZE);
	cw->ch[c].pc = cw_real_ptr(cw->ch[c].pc + args[1][3]);
	free_args(&(*args));
}
