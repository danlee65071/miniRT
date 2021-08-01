/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 08:04:47 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 08:04:49 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Парсинг данных для сферы*/
void	parse_sphere(t_scene *scene, char **parameters)
{
	int			quantity_parameters;
	t_sphere	new_sphere;
	char		**rgb;

	quantity_parameters = 0;
	while (parameters[quantity_parameters] != NULL)
		quantity_parameters++;
	if (quantity_parameters < 4 || quantity_parameters > 5)
		error_message("Error: Wrong number of sphere parameters!\n");
	parse_coordinates(&(new_sphere.center), parameters[1]);
	new_sphere.diameter = ft_atof(parameters[2]);
	rgb = ft_split(parameters[3], ',');
	assining_color(&(new_sphere.rgb), ft_atoi(rgb[0]), ft_atoi(rgb[1]),
		ft_atoi(rgb[2]));
	check_color(&new_sphere.rgb);
	if (quantity_parameters == 5)
		new_sphere.is_checkerboard = ft_atof(parameters[4]);
	else
		new_sphere.is_checkerboard = 0;
	new_sphere.ind = scene->shapes.qnty_spheres;
	add_sphere(scene, new_sphere);
	scene->shapes.qnty_spheres++;
	free_two_dimensional_string_array(rgb);
	scene->qnty_shapes++;
}
