/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:23:24 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/20 22:23:26 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(count * size);
	if (new_ptr != NULL)
		ft_memset(new_ptr, 0, count * size);
	return (new_ptr);
}
