/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:25:27 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 14:25:29 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Парсинг данных для плоскости.*/
void	parse_plane(t_scene *scene, char **parameters)
{
	int		qnty_params;
	t_plane	new_plane;
	char	**rgb;

	qnty_params = 0;
	while (parameters[qnty_params] != NULL)
		qnty_params++;
	if (qnty_params < 4 || qnty_params > 5)
		error_message("Error: Wrong number of plane parameters!\n");
	parse_coordinates(&(new_plane.coordiantes), parameters[1]);
	parse_coordinates(&(new_plane.orientation_vector), parameters[2]);
	check_orientation_vector(new_plane.orientation_vector);
	rgb = ft_split(parameters[3], ',');
	if (qnty_params == 5)
		new_plane.is_checkerboard = ft_atof(parameters[4]);
	else
		new_plane.is_checkerboard = 0;
	assining_color(&(new_plane.rgb), ft_atoi(rgb[0]), ft_atoi(rgb[1]),
		ft_atoi(rgb[2]));
	check_color(&new_plane.rgb);
	new_plane.ind = scene->shapes.qnty_planes;
	add_plane(scene, new_plane);
	scene->shapes.qnty_planes++;
	free_two_dimensional_string_array(rgb);
	scene->qnty_shapes++;
}
