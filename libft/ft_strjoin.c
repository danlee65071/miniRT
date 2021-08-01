/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:31:57 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/21 23:32:00 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_new_str(char *new_str, char const *s1, char const *s2, \
						size_t len_new_str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_new_str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_new_str = len_s1 + len_s2;
	new_str = malloc(sizeof(char) * (len_new_str + 1));
	if (!new_str)
		return (NULL);
	fill_new_str(new_str, s1, s2, len_new_str);
	return (new_str);
}

void	fill_new_str(char *new_str, char const *s1, char const *s2, \
						size_t len_new_str)
{
	size_t	i;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	i = 0;
	while (i < len_s1)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < len_new_str)
	{
		new_str[i] = s2[i - len_s1];
		i++;
	}
	new_str[i] = '\0';
}
