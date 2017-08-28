/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_prefight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:52:23 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 14:52:25 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void		cw_create_regs(t_cw *cw, int i)
{
	int x;

	cw->ch[i].reg[0] = cw->ch[i].num;
	x = 1;
	while (x < REG_NUMBER)
	{
		cw->ch[i].reg[x] = 0;
		x++;
	}
}

static void	cw_champ_inmem(t_cw *cw)
{
	int i;
	int j;

	i = -1;
	while (++i < cw->chcount)
	{
		j = -1;
		while (++j < cw->ch[i].csize)
			cw->vm.mem[cw->ch[i].load_mem + j] = cw->ch[i].ucmd[j];
	}
}

void		cw_prefight(t_cw *cw, int tmp)
{
	int i;

	cw->vm.mem = ft_ustrnew(MEM_SIZE);
	i = -1;
	while (++i < cw->chcount)
		tmp += cw->ch[i].csize;
	if (tmp > MEM_SIZE || cw->chcount > MAX_PLAYERS)
		cw_usage("Your champions too fat for corewar [cw_prefight]\n", cw);
	tmp = ((MEM_SIZE - tmp) / cw->chcount);
	i = -1;
	while (++i < cw->chcount)
	{
		cw_create_regs(cw, i);
		cw->ch[i].load_mem = (i == 0) ? 0 : (cw->ch[i - 1].load_mem + tmp * i);
		cw->ch[i].pc = cw->ch[i].load_mem;
	}
	cw_champ_inmem(cw);
	cw->vm.ctd = CYCLE_TO_DIE;
	cw->vm.cycle = 0;
	cw->vm.isdecr_maxcheck = false;
	cw->vm.nbr_live = 0;
	cw->vm.last_live = cw->chcount - 1;
	cw->chrc = cw->chcount;
}
