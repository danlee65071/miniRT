/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:23:40 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/20 22:23:42 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*new_str;

	len_s1 = ft_strlen(s1);
	new_str = malloc(sizeof(char) * (len_s1 + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, len_s1 + 1);
	return (new_str);
}
