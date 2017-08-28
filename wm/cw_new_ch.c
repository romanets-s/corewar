/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_new_ch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:44:04 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 14:44:09 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_new_ch(t_cw *cw)
{
	++cw->chcount;
	cw->ch = (t_ch*)realloc(cw->ch, sizeof(t_ch) * cw->chcount);
	cw->ch[cw->chcount - 1].ischampion = true;
	cw->ch[cw->chcount - 1].file = NULL;
	cw->ch[cw->chcount - 1].isnum = 0;
	cw->ch[cw->chcount - 1].num = 0;
	cw->ch[cw->chcount - 1].name = NULL;
	cw->ch[cw->chcount - 1].csize = 0;
	cw->ch[cw->chcount - 1].cmt = NULL;
	cw->ch[cw->chcount - 1].cmd = NULL;
	cw->ch[cw->chcount - 1].ucmd = NULL;
	cw->ch[cw->chcount - 1].pc = 0;
	cw->ch[cw->chcount - 1].carry = false;
	cw->ch[cw->chcount - 1].alive = true;
	cw->ch[cw->chcount - 1].live = 0;
	cw->ch[cw->chcount - 1].cpause = false;
	cw->ch[cw->chcount - 1].cycles = 0;
	cw->ch[cw->chcount - 1].color = 0;
	cw->ch[cw->chcount - 1].fork = 0;
}
