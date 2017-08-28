/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:37:48 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/23 20:47:47 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*temp;

	if ((temp = (unsigned char*)malloc(size)) == NULL)
		return (NULL);
	while (size != 0)
		temp[size--] = 0;
	temp[size] = 0;
	return (temp);
}
