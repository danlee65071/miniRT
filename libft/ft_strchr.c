/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:31:41 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/20 19:31:43 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;

	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i] != 0)
	{
		if (tmp_s[i] == c)
			return (&tmp_s[i]);
		i++;
	}
	if (c == '\0')
		return (&tmp_s[i]);
	return (NULL);
}
