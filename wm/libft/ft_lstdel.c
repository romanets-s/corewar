/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:07:54 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 17:53:25 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*kek;
	t_list	*lol;

	kek = *alst;
	lol = NULL;
	while (kek)
	{
		if (kek->next)
			lol = kek->next;
		else
			lol = NULL;
		del(kek->content, kek->content_size);
		free(kek);
		kek = lol;
	}
	*alst = NULL;
}
