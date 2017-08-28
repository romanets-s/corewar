/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_cpy_ch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:52:21 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 11:52:26 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static void	cw_cpy_ch_reg(t_cw *cw, int fr, int to)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		cw->ch[to].reg[i] = cw->ch[fr].reg[i];
}

void		cw_cpy_ch(t_cw *cw, int c, unsigned where, int ind)
{
	++cw->chcount;
	cw->ch = (t_ch*)realloc(cw->ch, sizeof(t_ch) * cw->chcount);
	cw->ch[cw->chcount - 1].ischampion = false;
	cw->ch[cw->chcount - 1].file = cw->ch[c].file;
	cw->ch[cw->chcount - 1].isnum = cw->ch[c].isnum;
	cw->ch[cw->chcount - 1].num = cw->ch[c].num;
	cw->ch[cw->chcount - 1].name = cw->ch[c].name;
	cw->ch[cw->chcount - 1].csize = cw->ch[c].csize;
	cw->ch[cw->chcount - 1].cmt = cw->ch[c].cmt;
	cw->ch[cw->chcount - 1].cmd = cw->ch[c].cmd;
	cw->ch[cw->chcount - 1].ucmd = cw->ch[c].ucmd;
	cw_cpy_ch_reg(cw, c, cw->chcount - 1);
	cw->ch[cw->chcount - 1].pc = cw->ch[c].pc + (where % (ind ? IDX_MOD : 1));
	cw->ch[cw->chcount - 1].carry = false;
	cw->ch[cw->chcount - 1].alive = true;
	cw->ch[cw->chcount - 1].live = 0;
	cw->ch[cw->chcount - 1].load_mem = cw->ch[c].load_mem;
	cw->ch[cw->chcount - 1].cpause = false;
	cw->ch[cw->chcount - 1].cycles = 0;
	cw->ch[cw->chcount - 1].fork = c;
}
