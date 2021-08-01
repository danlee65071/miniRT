/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:57:01 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/20 19:57:04 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len_s;
	char		*tmp_s;

	tmp_s = (char *)s;
	len_s = ft_strlen(s);
	if ((char)c == '\0')
		return (&tmp_s[len_s]);
	while (len_s > 0)
	{
		if (tmp_s[len_s] == (char)c)
			return (&tmp_s[len_s]);
		len_s--;
	}
	if (tmp_s[len_s] == (char)c)
		return (&tmp_s[len_s]);
	return (NULL);
}
