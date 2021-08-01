/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_paraboloid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:39:06 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/30 09:39:08 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	add_paraboloid(t_scene *scene, t_paraboloid new_paraboloid_parameters)
{
	t_paraboloid	*tmp;
	int				i;

	tmp = scene->shapes.paraboloid;
	scene->shapes.paraboloid = malloc(sizeof(t_paraboloid)
			* (scene->shapes.qnty_paraboloids + 1));
	if (scene->shapes.paraboloid == NULL)
		error_message("Error: Malloc error!\n");
	i = -1;
	while (++i < scene->shapes.qnty_paraboloids)
		scene->shapes.paraboloid[i] = tmp[i];
	scene->shapes.paraboloid[i].extremum = new_paraboloid_parameters.extremum;
	scene->shapes.paraboloid[i].orientation_vector
		= new_paraboloid_parameters.orientation_vector;
	scene->shapes.paraboloid[i].orientation_vector
		= norm_vector(scene->shapes.paraboloid[i].orientation_vector);
	scene->shapes.paraboloid[i].dist_to_kernel
		= new_paraboloid_parameters.dist_to_kernel;
	scene->shapes.paraboloid[i].rgb = new_paraboloid_parameters.rgb;
	scene->shapes.paraboloid[i].ind = new_paraboloid_parameters.ind;
	scene->shapes.paraboloid[i].is_checkerboard
		= new_paraboloid_parameters.is_checkerboard;
	if (tmp != NULL)
		free(tmp);
}
