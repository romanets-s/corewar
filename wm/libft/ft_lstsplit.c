/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:21:39 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/03 18:37:46 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsplit(char const *str, char c)
{
	char	**fresh;
	t_list	*lst;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	fresh = ft_strsplit(str, c);
	lst = ft_lstnew(fresh[i], ft_strlen(fresh[i]));
	i++;
	while (fresh[i])
	{
		lstbac(&lst, fresh[i], ft_strlen(fresh[i]));
		i++;
	}
	return (lst);
}
