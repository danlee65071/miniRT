/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:10:06 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/20 20:10:09 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;

	h = (char *)haystack;
	if (*needle == '\0' || len == 0)
		return (h);
	i = 0;
	while (i < len && h[i] != '\0')
	{
		if (h[i] == needle[0])
		{
			j = 0;
			while (needle[j] != '\0' && h[i + j] != '\0' && (i + j) < len)
			{
				if (needle[j] != h[i + j])
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return (&h[i]);
		}
		i++;
	}
	return (NULL);
}
