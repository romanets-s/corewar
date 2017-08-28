/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vis_refresh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 06:42:24 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/21 06:42:25 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void		cw_vis_pc(t_cw *cw)
{
	int i;
	int	j;

	i = -1;
	j = 1;
	while (++i < cw->chrc)
	{
		init_pair(9 + j, COLOR_BLACK, j);
		attron(COLOR_PAIR(9 + j));
		mvprintw(cw->ch[i].pc ? (cw->ch[i].pc / VM_MEM_INLINE + 2) : 2,
			(cw->ch[i].pc % VM_MEM_INLINE) * 3 + 2, "%.2x",
			cw->vm.mem[cw->ch[i].pc]);
		attroff(COLOR_PAIR(9 + j));
		j++;
	}
	refresh();
}

static void	key_options(t_cw *cw, int key, bool flag)
{
	if (key == 32)
		cw->vis.pause = flag;
	if (key == 65)
		cw_vis_cps_up(cw);
	if (key == 66)
		cw_vis_cps_down(cw);
}

static void	cycles_options(t_cw *cw)
{
	double	time;

	if (!cw->vis.cycles)
	{
		cw->vis.cstart = clock();
		cw->vis.cycles = 1;
	}
	else if (cw->vis.cycles > cw->vis.cps)
	{
		if ((time = ((1 - ((double)(clock() - cw->vis.cstart) /
			(double)CLOCKS_PER_SEC)))) > 0)
		{
			time *= 1000000;
			usleep(time);
		}
		cw->vis.cycles = 0;
	}
	else
		++cw->vis.cycles;
}

void		cw_vis_refresh(t_cw *cw)
{
	int		key;

	nodelay(cw->vis.win, TRUE);
	key = getch();
	key_options(cw, key, 1);
	while (cw->vis.pause)
	{
		key = getch();
		key_options(cw, key, 0);
		cw_draw_options(cw);
	}
	cycles_options(cw);
	cw_draw_players(cw, -1);
	cw_draw_options(cw);
	cw_vis_output(cw, 2, 2);
}
