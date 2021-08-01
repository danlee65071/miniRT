/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:34:49 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/16 21:34:59 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	size_t	i;
	char	*tmp_d;
	char	*tmp_s;

	tmp_d = (char *)d;
	tmp_s = (char *)s;
	i = 0;
	if (s < d)
	{
		while (n > 0)
		{
			tmp_d[n - 1] = tmp_s[n - 1];
			n--;
		}
	}
	else if (s > d)
	{
		while (i < n)
		{
			tmp_d[i] = tmp_s[i];
			i++;
		}
	}
	return (d);
}
