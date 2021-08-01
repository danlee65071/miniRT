/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:22:36 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/24 12:22:37 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Увелечение яркости цвета в num раз*/
t_rgb	color_product_num(t_rgb rgb, float num)
{
	t_rgb	res;

	res.r = rgb.r * num;
	res.g = rgb.g * num;
	res.b = rgb.b * num;
	return (res);
}

/*Смешивание двух цветов*/
t_rgb	color_sum(t_rgb rgb1, t_rgb rgb2)
{
	t_rgb	res;

	res.r = rgb1.r + rgb2.r;
	res.g = rgb1.g + rgb2.g;
	res.b = rgb1.b + rgb2.b;
	return (res);
}

/*Получение инверсного цвета*/
t_rgb	inverse_color(t_rgb rgb)
{
	t_rgb	res;
	int		medium_val;
	t_rgb	diff;

	medium_val = 255 / 2;
	diff.r = rgb.r - medium_val;
	diff.g = rgb.g - medium_val;
	diff.b = rgb.b - medium_val;
	res.r = medium_val - diff.r;
	res.g = medium_val - diff.g;
	res.b = medium_val - diff.b;
	return (res);
}
