/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:06:09 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/21 23:06:17 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str || start < 0 || len < 0 || !s)
		return (NULL);
	sub_str[len] = '\0';
	i = 0;
	while (s[i] && len > 0)
	{
		if (i >= start)
		{
			sub_str[i - start] = s[i];
			len--;
		}
		i++;
	}
	return (sub_str);
}
