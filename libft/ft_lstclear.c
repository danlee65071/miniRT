/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:29:37 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/24 02:29:39 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_el;
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		next_el = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next_el;
	}
	*lst = NULL;
}
