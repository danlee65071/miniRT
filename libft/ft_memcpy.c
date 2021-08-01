/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:38:42 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/16 20:38:45 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t	i;
	char	*tmp_d;
	char	*tmp_s;

	tmp_d = (char *)d;
	tmp_s = (char *)s;
	if (!d && !s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp_d[i] = tmp_s[i];
		i++;
	}
	return (d);
}
