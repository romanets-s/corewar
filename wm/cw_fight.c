/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:12:06 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 12:12:13 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static void	cw_step2(t_cw *cw, int c)
{
	if (cw->vm.mem[cw->ch[c].pc] == 0x0c)
		cw_vm_fork(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x0d)
		cw_vm_lld(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x0e)
		cw_vm_lldi(cw, c, -1);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x0f)
		cw_vm_lfork(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x10)
		cw_vm_aff(cw, c);
	else
		cw_vm_next(cw, c);
}

static void	cw_step(t_cw *cw, int c)
{
	if (cw->vm.mem[cw->ch[c].pc] == 0x01)
		cw_vm_live(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x02)
		cw_vm_ld(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x03)
		cw_vm_st(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x04)
		cw_vm_add(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x05)
		cw_vm_sub(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x06)
		cw_vm_and(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x07)
		cw_vm_or(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x08)
		cw_vm_xor(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x09)
		cw_vm_zjmp(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x0a)
		cw_vm_ldi(cw, c);
	else if (cw->vm.mem[cw->ch[c].pc] == 0x0b)
		cw_vm_sti(cw, c);
	else
		cw_step2(cw, c);
}

void		cw_fight(t_cw *cw)
{
	int c;

	c = cw->chcount;
	while (--c > -1)
	{
		if (cw->ch[c].alive)
		{
			if (cw->ch[c].cpause)
				--cw->ch[c].cycles;
			if (!cw->ch[c].cycles)
				cw_step(cw, c);
		}
	}
}
