/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:33:12 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/21 19:33:13 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Парсинг данных для окружающего света.*/
void	parse_ambient(t_scene *scene, char **parameters)
{
	int		quantity_parameters;
	char	**rgb;

	if (scene->ambient.quantity != 0)
		error_message("Error: The number of ambient lightning can only be "
			"one!\n");
	scene->ambient.quantity++;
	scene->qnty_light_source++;
	quantity_parameters = 0;
	while (parameters[quantity_parameters] != NULL)
		quantity_parameters++;
	if (quantity_parameters != 3)
		error_message("Error: Wrong number of ambient lightning "
			"parameters!\n");
	scene->ambient.lighting = ft_atof(parameters[1]);
	check_brightness(scene->ambient.lighting);
	rgb = ft_split(parameters[2], ',');
	assining_color(&(scene->ambient.rgb), ft_atoi(rgb[0]), ft_atoi(rgb[1]),
		ft_atoi(rgb[2]));
	check_color(&(scene->ambient.rgb));
	free_two_dimensional_string_array(rgb);
}
