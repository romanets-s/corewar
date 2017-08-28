/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_the_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:47:34 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 16:47:46 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_the_end(t_cw *cw)
{
	if (cw->visual)
	{
		attron(COLOR_PAIR(1));
		mvprintw(cw->vis.vids + cw->chrc * 3 + 14, cw->vis.width - SUB_MENU,
			" WINNER:                  ");
		mvprintw(cw->vis.vids + cw->chrc * 3 + 15, cw->vis.width - SUB_MENU,
			" |%.38s|", cw->ch[cw->vm.last_live].name);
		attroff(COLOR_PAIR(1));
		nodelay(cw->vis.win, FALSE);
		if (getch() != -1)
			endwin();
	}
	else
	{
		ft_putstr("VICTORY! |");
		ft_putstr(cw->ch[cw->vm.last_live].name);
		ft_putstr("| WON!\n");
	}
	exit(0);
}
