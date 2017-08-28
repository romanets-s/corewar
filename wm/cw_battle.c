/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_battle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:48:18 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 11:48:27 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static int	cw_isgame(t_cw *cw)
{
	int	i;

	i = -1;
	while (++i < cw->chrc)
		if (cw->ch[i].alive)
			return (1);
	return (0);
}

static void	cw_decr_ctd(t_cw *cw)
{
	if (!cw->vm.cycle)
		return ;
	if (cw->vm.ctd < CYCLE_DELTA)
	{
		cw->vm.ctd = 1;
		return ;
	}
	cw->vm.ctd -= CYCLE_DELTA;
	cw->vm.isdecr_maxcheck = true;
}

static void	cw_die_check(t_cw *cw, int i)
{
	int players;

	players = 0;
	if (!cw->vm.cycle)
		return ;
	while (++i < cw->chrc)
	{
		if (cw->ch[i].alive && !cw->ch[i].live)
		{
			cw_burn_them_all(cw, cw->ch[i].num);
			cw->ch[i].alive = false;
			system("afplay beep-02.mp3");
		}
		else if (cw->ch[i].alive)
		{
			cw->ch[i].live = 0;
			++players;
		}
	}
	if (cw->vm.nbr_live >= NBR_LIVE)
		cw_decr_ctd(cw);
	cw->vm.nbr_live = 0;
	if (!players)
		cw_the_end(cw);
}

void		cw_battle(t_cw *cw)
{
	while (cw_isgame(cw))
	{
		if (cw->visual)
			cw_vis_refresh(cw);
		if (!(cw->vm.cycle % cw->vm.ctd))
			cw_die_check(cw, -1);
		if (cw->vm.checks >= MAX_CHECKS)
		{
			cw->vm.checks = 0;
			if (!cw->vm.isdecr_maxcheck)
				cw_decr_ctd(cw);
			cw->vm.isdecr_maxcheck = false;
		}
		cw_fight(cw);
		if (cw->dump == cw->vm.cycle && cw->isdump && !cw->visual)
			cw_output(cw);
		++cw->vm.cycle;
	}
	cw_the_end(cw);
}
