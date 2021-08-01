/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:38:32 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 12:38:35 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	add_sphere(t_scene *scene, t_sphere sphere_parameters)
{
	t_sphere	*tmp;
	int			i;

	tmp = scene->shapes.sphere;
	scene->shapes.sphere = malloc(sizeof(t_sphere)
			* (scene->shapes.qnty_spheres + 1));
	if (scene->shapes.sphere == NULL)
		error_message("Error: Malloc error!\n");
	i = -1;
	while (++i < scene->shapes.qnty_spheres)
		scene->shapes.sphere[i] = tmp[i];
	scene->shapes.sphere[i].center = sphere_parameters.center;
	scene->shapes.sphere[i].diameter = sphere_parameters.diameter;
	scene->shapes.sphere[i].rgb = sphere_parameters.rgb;
	scene->shapes.sphere[i].ind = sphere_parameters.ind;
	scene->shapes.sphere[i].is_checkerboard = sphere_parameters.is_checkerboard;
	if (tmp != NULL)
		free(tmp);
}
