/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:21:30 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 14:21:31 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	add_plane(t_scene *scene, t_plane new_plane_parameters)
{
	t_plane	*tmp;
	int		i;

	tmp = scene->shapes.plane;
	scene->shapes.plane = malloc(sizeof(t_plane)
			* (scene->shapes.qnty_planes + 1));
	if (scene->shapes.plane == NULL)
		error_message("Error: Malloc error!\n");
	i = -1;
	while (++i < scene->shapes.qnty_planes)
		scene->shapes.plane[i] = tmp[i];
	scene->shapes.plane[i].coordiantes = new_plane_parameters.coordiantes;
	scene->shapes.plane[i].orientation_vector
		= new_plane_parameters.orientation_vector;
	scene->shapes.plane[i].rgb = new_plane_parameters.rgb;
	scene->shapes.plane[i].ind = new_plane_parameters.ind;
	scene->shapes.plane[i].is_checkerboard
		= new_plane_parameters.is_checkerboard;
	if (tmp != NULL)
		free(tmp);
}
