/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 06:39:39 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/21 06:39:40 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

int		cw_find_index(t_cw *cw, int num)
{
	int i;

	i = -1;
	while (++i < cw->chrc)
		if (cw->ch[i].num == num)
			return (i);
	return (-1);
}

void	cw_burn_them_all(t_cw *cw, int num)
{
	int i;

	i = -1;
	while (++i < cw->chcount)
	{
		if (cw->ch[i].num == num)
		{
			cw->ch[i].alive = false;
			cw->ch[i].live = 0;
		}
	}
}
