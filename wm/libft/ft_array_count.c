/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 19:19:46 by irepeta           #+#    #+#             */
/*   Updated: 2017/06/27 19:20:17 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_count(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
