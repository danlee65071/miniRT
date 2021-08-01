/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:44:38 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/30 19:44:39 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Линейная интерполяция цвета.
 * (В нашей программе параметр t равен 0 или 1).*/
t_rgb	lerp_color(t_rgb rgb1, t_rgb rgb2, float t)
{
	t_rgb	res;

	res.r = rgb1.r * (1 - t) + rgb2.r * t;
	res.g = rgb1.g * (1 - t) + rgb2.g * t;
	res.b = rgb1.b * (1 - t) + rgb2.b * t;
	return (res);
}

/*Очищение массива строк.*/
void	free_two_dimensional_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
