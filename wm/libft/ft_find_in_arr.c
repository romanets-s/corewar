/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 18:22:29 by irepeta           #+#    #+#             */
/*   Updated: 2017/06/27 18:22:29 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_in_arr(char **where, char *what)
{
	int i;

	i = 0;
	while (where[i])
	{
		if (!strcmp(where[i], what))
			return (1);
		i++;
	}
	return (0);
}
