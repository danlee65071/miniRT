/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:11:00 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/24 12:11:02 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Проверка значений цвета*/
/*Если компонент цвета (r, g, b) меньше 0, то присваиваем этому компоненту
 * значение 0.
 * Если компонент цвета (r, g, b) больше 255, то присваиваем этому компоненту
 * значение 255.*/
void	check_color(t_rgb *rgb)
{
	if (rgb->r < 0)
		rgb->r = 0;
	else if (rgb->r > 255)
		rgb->r = 255;
	if (rgb->g < 0)
		rgb->g = 0;
	else if (rgb->g > 255)
		rgb->g = 255;
	if (rgb->b < 0)
		rgb->b = 0;
	else if (rgb->b > 255)
		rgb->b = 255;
}

/*Присвание переменной rgb цвета по заданным параметрам red, green, blue.*/
void	assining_color(t_rgb *rgb, int red, int green, int blue)
{
	rgb->r = red;
	rgb->g = green;
	rgb->b = blue;
}

/*Проверка яркости*/
/*Если яркость меньше 0 или больше 1, то программа завершается с выводом на
 * экран ошибки.*/
void	check_brightness(float brightness)
{
	if (brightness < 0 || brightness > 1)
		error_message("Error: Wrong value brightness!\n");
}

/*Перевод цвета из (r, g, b) в шестнадцатеричное число*/
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*Добавление цвету яроксти*/
t_rgb	add_brightness(t_rgb rgb, t_brightness brightness)
{
	t_rgb	res;

	res.r = brightness.brightness * (rgb.r + brightness.r);
	res.g = brightness.brightness * (rgb.g + brightness.g);
	res.b = brightness.brightness * (rgb.b + brightness.b);
	check_color(&res);
	return (res);
}
