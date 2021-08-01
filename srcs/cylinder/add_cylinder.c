/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:37:25 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 16:37:26 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Добавление цилиндра в сцену.*/
void	add_cylinder(t_scene *scene, t_cylinder new_cylinder_parameters)
{
	t_cylinder	*tmp;
	int			i;

	tmp = scene->shapes.cylinder;
	scene->shapes.cylinder = malloc(sizeof(t_cylinder)
			* (scene->shapes.qnty_cylinders + 1));
	if (scene->shapes.cylinder == NULL)
		error_message("Error: Malloc error!\n");
	i = -1;
	while (++i < scene->shapes.qnty_cylinders)
		scene->shapes.cylinder[i] = tmp[i];
	scene->shapes.cylinder[i].coordinates = new_cylinder_parameters.coordinates;
	scene->shapes.cylinder[i].orientation_vector
		= new_cylinder_parameters.orientation_vector;
	scene->shapes.cylinder[i].diameter = new_cylinder_parameters.diameter;
	scene->shapes.cylinder[i].height = new_cylinder_parameters.height;
	scene->shapes.cylinder[i].rgb = new_cylinder_parameters.rgb;
	scene->shapes.cylinder[i].ind = new_cylinder_parameters.ind;
	scene->shapes.cylinder[i].is_checkerboard
		= new_cylinder_parameters.is_checkerboard;
	if (tmp != NULL)
		free(tmp);
}
