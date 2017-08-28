/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:06:16 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 18:01:18 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int character)
{
	if ((character >= 'A' && character <= 'Z')
			|| (character >= 'a' && character <= 'z')
			|| (character >= '0' && character <= '9'))
		return (1);
	return (0);
}
