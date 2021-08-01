/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:32:01 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/30 11:32:02 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Парсинг данных для параболоидв.*/
void	parse_paraboloid(t_scene *scene, char **parameters)
{
	int				quantity_parameters;
	t_paraboloid	new_paraboloid;
	char			**rgb;

	quantity_parameters = 0;
	while (parameters[quantity_parameters] != NULL)
		quantity_parameters++;
	if (quantity_parameters < 5 || quantity_parameters > 6)
		error_message("Error: Wrong number of paraboloid parameters!\n");
	parse_coordinates(&(new_paraboloid.extremum), parameters[1]);
	parse_coordinates(&(new_paraboloid.orientation_vector), parameters[2]);
	new_paraboloid.dist_to_kernel = ft_atof(parameters[3]);
	rgb = ft_split(parameters[4], ',');
	assining_color(&(new_paraboloid.rgb), ft_atoi(rgb[0]), ft_atoi(rgb[1]),
		ft_atoi(rgb[2]));
	check_color(&new_paraboloid.rgb);
	if (quantity_parameters == 6)
		new_paraboloid.is_checkerboard = ft_atof(parameters[5]);
	else
		new_paraboloid.is_checkerboard = 0;
	new_paraboloid.ind = scene->shapes.qnty_spheres;
	add_paraboloid(scene, new_paraboloid);
	scene->shapes.qnty_paraboloids++;
	free_two_dimensional_string_array(rgb);
	scene->qnty_shapes++;
}
