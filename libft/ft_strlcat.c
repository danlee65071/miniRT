/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:55:02 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/20 18:55:04 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	res;
	size_t	i;
	size_t	begin_dst;

	begin_dst = 0;
	while (dst[begin_dst] && begin_dst < dstsize)
		begin_dst++;
	res = begin_dst + ft_strlen(src);
	if (begin_dst < dstsize)
	{
		i = 0;
		while (src[i] != '\0' && i < (dstsize - begin_dst - 1))
		{
			dst[begin_dst + i] = src[i];
			i++;
		}
		dst[begin_dst + i] = '\0';
	}
	return (res);
}
