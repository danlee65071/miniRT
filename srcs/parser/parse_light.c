/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 07:42:58 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 07:43:01 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*	if (scene->light.quantity != 0)
		error_message("Error: The number of light can only be one!\n");*/
/*Парсинг данных для точечного света.*/
void	parse_light(t_scene *scene, char **parameters)
{
	int		quantity_parameters;
	t_light	new_light;
	char	**rgb;

	quantity_parameters = 0;
	while (parameters[quantity_parameters] != NULL)
		quantity_parameters++;
	if (quantity_parameters < 3 || quantity_parameters > 4)
		error_message("Error: Wrong number of light parameters!\n");
	parse_coordinates(&(new_light.coordinates), parameters[1]);
	new_light.brightness = ft_atof(parameters[2]);
	check_brightness(new_light.brightness);
	if (quantity_parameters == 4)
	{
		rgb = ft_split(parameters[3], ',');
		assining_color(&(new_light.rgb), ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]));
		free_two_dimensional_string_array(rgb);
	}
	add_light(scene, new_light);
	scene->light_quantity++;
	scene->qnty_light_source++;
}
