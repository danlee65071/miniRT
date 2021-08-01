/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:58:45 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/20 19:58:50 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Запись пикселей*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*Вывод сообщения об ошибке в лог ошибок и завершение программы*/
void	error_message(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	exit (1);
}

/*Вычисление числа после точки у дробного числа*/
static void	ft_atof_after_point(float *num, char *str)
{
	int		num_after_point;
	char	c;

	num_after_point = 0;
	str++;
	c = *str;
	while (c != '\0' && ft_isdigit(c))
	{
		*num = *num * 10 + (float)(c - '0');
		str++;
		c = *str;
		num_after_point++;
	}
	if (c != '\0')
		error_message("Error: Wrong parameter!\n");
	while (num_after_point > 0)
	{
		*num /= 10;
		num_after_point--;
	}
}

/*Перевод дробного числа из стркового типа в тип float*/
float	ft_atof(char *str)
{
	float	num;
	char	c;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	num = 0;
	c = *str;
	while (c != '\0' && ft_isdigit(c))
	{
		num = num * 10 + (float)(c - '0');
		str++;
		c = *str;
	}
	if (c == '.')
		ft_atof_after_point(&num, str);
	else if (c != '\0')
		error_message("Error: Wrong parameter!\n");
	return (num * sign);
}
