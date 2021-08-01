/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:04:40 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/24 01:04:41 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len_list;
	t_list	*tmp;

	len_list = 0;
	tmp = lst;
	while (tmp)
	{
		len_list++;
		tmp = tmp->next;
	}
	return (len_list);
}
