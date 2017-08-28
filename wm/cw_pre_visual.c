/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_pre_visual.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 06:42:34 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/21 06:42:35 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static void	some_init(t_cw *cw, int col)
{
	cw->vis.cps = 42;
	cw->vis.cstart = 0;
	cw->vis.vids = 0;
	cw->vis.pause = 1;
	cw->vis.width = VM_MEM_INLINE * 3 + 1 + 3 + SUB_MENU;
	cw->vis.height = col + 4;
	cw->vis.win = initscr();
}

static void	some_print(t_cw *cw, int i)
{
	mvprintw(i, 0, "*");
	mvprintw(i, VM_MEM_INLINE * 3 + 2, "*");
	mvprintw(i, cw->vis.width - 1, "*");
}

static void	some_functions(t_cw *cw)
{
	cw_vis_output(cw, 2, 2);
	cw_draw_players(cw, -1);
	cw_draw_options(cw);
}

void		cw_pre_visual(t_cw *cw, int i, int col)
{
	some_init(cw, col);
	noecho();
	curs_set(0);
	if (col < 25)
		col = 25;
	if (has_colors() == FALSE)
	{
		cw_usage("Your terminal does not support color\n", cw);
		exit(0);
	}
	start_color();
	init_pair(8, COLOR_BLUE, COLOR_BLUE);
	attron(COLOR_PAIR(8));
	i = -1;
	while (++i < cw->vis.width)
	{
		mvprintw(0, i, "*");
		mvprintw(col + 3, i, "*");
		if (i < col + 4)
			some_print(cw, i);
	}
	attroff(COLOR_PAIR(8));
	init_pair(9, COLOR_MAGENTA, COLOR_BLACK);
	some_functions(cw);
	refresh();
}
