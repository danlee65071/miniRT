/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:25:32 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 16:25:33 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	sup_parse_cylinder(char **parameters, int *qnty_params);

/*Парсинг данных для цилиндра.*/
void	parse_cylinder(t_scene *scene, char **parameters)
{
	int			qnty_params;
	t_cylinder	new_cylinder;
	char		**rgb;

	sup_parse_cylinder(parameters, &qnty_params);
	parse_coordinates(&(new_cylinder.coordinates), parameters[1]);
	parse_coordinates(&(new_cylinder.orientation_vector), parameters[2]);
	check_orientation_vector(new_cylinder.orientation_vector);
	new_cylinder.diameter = ft_atof(parameters[3]);
	new_cylinder.height = ft_atof(parameters[4]);
	rgb = ft_split(parameters[5], ',');
	assining_color(&(new_cylinder.rgb), ft_atoi(rgb[0]), ft_atoi(rgb[1]),
		ft_atoi(rgb[2]));
	if (qnty_params == 7)
		new_cylinder.is_checkerboard = ft_atof(parameters[6]);
	else
		new_cylinder.is_checkerboard = 0;
	new_cylinder.ind = scene->shapes.qnty_cylinders;
	add_cylinder(scene, new_cylinder);
	scene->shapes.qnty_cylinders++;
	free_two_dimensional_string_array(rgb);
	scene->qnty_shapes++;
}

/*Вспомогательная функция для парсинга цилиндра.*/
static void	sup_parse_cylinder(char **parameters, int *qnty_params)
{
	*qnty_params = 0;
	while (parameters[*qnty_params] != NULL)
		(*qnty_params)++;
	if (*qnty_params < 6 || *qnty_params > 7)
		error_message("Error: Wrong number of cylinder parameters!\n");
}
