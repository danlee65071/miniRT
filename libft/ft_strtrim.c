/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:45:35 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/21 23:45:38 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_begin(char const *s1, char const *set)
{
	size_t	begin;

	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	return (begin);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[end]) && end > 0)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	begin;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return ("");
	begin = find_begin(s1, set);
	end = find_end(s1, set);
	if (begin >= end)
	{
		s = malloc(sizeof(char));
		s[0] = '\0';
		return (s);
	}
	s = malloc(sizeof(char) * (end - begin + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (begin <= end)
		s[i++] = s1[begin++];
	s[i] = '\0';
	return (s);
}
