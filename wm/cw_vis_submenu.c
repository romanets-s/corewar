/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vis_submenu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 06:50:33 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/21 06:50:34 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static void	cw_draw_players_continue(t_cw *cw, int i)
{
	int	j;

	j = 0;
	while (++i < cw->chrc)
	{
		attron(COLOR_PAIR(i + 1));
		mvprintw(cw->vis.vids + j, cw->vis.width - SUB_MENU,
			" P%d: %.33s", cw->ch[i].num, cw->ch[i].name);
		j++;
		mvprintw(cw->vis.vids + j, cw->vis.width - SUB_MENU,
			" Lives: %d                ", cw->ch[i].live);
		j += 2;
		attroff(COLOR_PAIR(cw->ch[i].color));
	}
}

void		cw_draw_players(t_cw *cw, int i)
{
	short int	colors;

	if (!cw->vis.vids)
		cw->vis.vids = (cw->vis.height - (cw->chrc * 3 + 16)) / 2;
	i = -1;
	if (!cw->ch[0].color)
	{
		colors = 1;
		while (++i < cw->chrc)
		{
			cw->ch[i].color = colors;
			init_pair(colors, colors, COLOR_BLACK);
			colors++;
			if (colors > 7)
				colors = 1;
		}
		i = -1;
	}
	cw_draw_players_continue(cw, i);
	refresh();
}

void		cw_draw_options(t_cw *cw)
{
	char	*tab;

	tab = "----------------------------------------\0";
	attron(COLOR_PAIR(9));
	mvprintw(cw->vis.vids + cw->chrc * 3, cw->vis.width - SUB_MENU, "%s", tab);
	mvprintw(cw->vis.vids + cw->chrc * 3 + 2, cw->vis.width - SUB_MENU,
		" CYCLE_TO_DIE: %u             ", cw->vm.ctd);
	mvprintw(cw->vis.vids + cw->chrc * 3 + 4, cw->vis.width - SUB_MENU,
		" CYCLE_DELTA: %d          ", CYCLE_DELTA);
	mvprintw(cw->vis.vids + cw->chrc * 3 + 6, cw->vis.width - SUB_MENU,
		" NBR_LIVE: %d               ", NBR_LIVE);
	mvprintw(cw->vis.vids + cw->chrc * 3 + 8, cw->vis.width - SUB_MENU,
		" LIVES_FROM_LAST_CTD: %d              ", cw->vm.nbr_live);
	mvprintw(cw->vis.vids + cw->chrc * 3 + 10, cw->vis.width - SUB_MENU,
		" CYCLES: %d            ", cw->vm.cycle);
	mvprintw(cw->vis.vids + cw->chrc * 3 + 12, cw->vis.width - SUB_MENU,
		" CYCLES PER SECOND: %d            ", cw->vis.cps);
	if (cw->vis.pause)
		mvprintw(cw->vis.vids + cw->chrc * 3 + 14, cw->vis.width - SUB_MENU,
			"***PAUSED***    ");
	else
		mvprintw(cw->vis.vids + cw->chrc * 3 + 14, cw->vis.width - SUB_MENU,
			"***LIVE***          ");
	attroff(COLOR_PAIR(9));
	refresh();
}
