/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:46:25 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/24 02:46:28 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;
	t_list	*new_el;
	bool	is_begin;

	if (!lst || !f)
		return (NULL);
	is_begin = true;
	tmp = lst;
	while (tmp)
	{
		new_el = ft_lstnew(f(tmp->content));
		if (!new_el)
			ft_lstclear(&new_list, del);
		if (is_begin)
		{
			new_list = new_el;
			is_begin = 0;
		}
		else
			ft_lstadd_back(&new_list, new_el);
		tmp = tmp->next;
	}
	return (new_list);
}
