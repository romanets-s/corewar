/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:25:22 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/05 17:49:44 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*str;
	t_list	*ptr;

	if (!lst || !(lst->content))
		return (NULL);
	str = lst;
	if ((tmp = (t_list*)malloc(sizeof(t_list) * ft_list_size(lst))) == NULL)
		return (NULL);
	tmp = f(ft_lstnew(str->content, str->content_size));
	ptr = tmp;
	while (str->next)
	{
		str = str->next;
		tmp->next = f(ft_lstnew(str->content, str->content_size));
		tmp = tmp->next;
	}
	return (ptr);
}
