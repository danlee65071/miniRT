/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 00:41:32 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/23 00:41:35 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	size_t	i;
	char	*modified_s;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	modified_s = malloc(sizeof(char) * (len_s + 1));
	if (!modified_s)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		modified_s[i] = (*f)(i, s[i]);
		i++;
	}
	modified_s[i] = '\0';
	return (modified_s);
}
