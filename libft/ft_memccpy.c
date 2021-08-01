/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:06:25 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/16 21:06:27 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	tmp_d = (unsigned char *)d;
	tmp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp_d[i] = tmp_s[i];
		if (tmp_s[i] == (unsigned char)c)
			return (&tmp_d[i + 1]);
		i++;
	}
	return (NULL);
}
