/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:43:29 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/21 20:43:30 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	check_fov(float fov);

/*Парсинг данных для камеры.*/
void	parse_camera(t_scene *scene, char **parameters)
{
	int	quantity_parameters;

	if (scene->camera.quantity != 0)
		error_message("Error: The number of camera can only be one!\n");
	scene->camera.quantity++;
	quantity_parameters = 0;
	while (parameters[quantity_parameters] != NULL)
		quantity_parameters++;
	if (quantity_parameters != 4)
		error_message("Error: Wrong number of camera parameters!\n");
	parse_coordinates(&(scene->camera.view_point), parameters[1]);
	parse_coordinates(&(scene->camera.orientation_vector), parameters[2]);
	check_orientation_vector(scene->camera.orientation_vector);
	scene->camera.orientation_vector
		= norm_vector(scene->camera.orientation_vector);
	scene->camera.fov = ft_atof(parameters[3]);
	check_fov(scene->camera.fov);
	scene->view_port_width = 2 * tanf(scene->camera.fov * M_PI / 360);
	scene->view_port_height = scene->view_port_width / scene->aspect_ratio;
}

/*Проверка угла обзора камеры.*/
static void	check_fov(float fov)
{
	if (fov < 0 || fov > 180)
		error_message("Error: Wrong FOV!\n");
}
