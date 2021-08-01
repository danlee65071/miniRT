/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:17:50 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/22 22:17:53 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		length_num(long unsign_n, int sign);
void	prepare_to_itoa(int n, long *unsign_n, int *sign);

char	*ft_itoa(int n)
{
	long	unsign_n;
	int		sign;
	int		len_n;
	char	*s;

	unsign_n = 0;
	sign = 0;
	prepare_to_itoa(n, &unsign_n, &sign);
	len_n = length_num(unsign_n, sign);
	s = malloc(sizeof(char) * (len_n + 1));
	if (!s)
		return (NULL);
	s[len_n] = '\0';
	len_n--;
	while (unsign_n != 0)
	{
		s[len_n] = unsign_n % 10 + '0';
		len_n--;
		unsign_n /= 10;
	}
	if (sign == -1)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	return (s);
}

int	length_num(long unsign_n, int sign)
{
	int	len;

	len = 0;
	if (unsign_n == 0)
		return (1);
	while (unsign_n != 0)
	{
		unsign_n /= 10;
		len++;
	}
	if (sign == -1)
		len++;
	return (len);
}

void	prepare_to_itoa(int n, long *unsign_n, int *sign)
{
	if (n < 0)
	{
		*unsign_n = (-1) * (long)n;
		*sign = -1;
	}
	else
	{
		*unsign_n = n;
		*sign = 1;
	}
}
