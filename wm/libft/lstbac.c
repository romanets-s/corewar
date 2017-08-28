/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstbac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:03:34 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/03 18:03:52 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstbac(t_list **begin_list, void *data, size_t content_siz)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = ft_lstnew(data, content_siz);
	}
	else
		*begin_list = ft_lstnew(data, content_siz);
}
