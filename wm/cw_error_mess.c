/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_error_mess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:10:59 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 12:11:00 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_usage(char *error, t_cw *cw)
{
	if (!error)
		ft_putstr("ERROR\n");
	else
		ft_putstr(error);
	if (cw->visual)
		endwin();
	exit(0);
}
