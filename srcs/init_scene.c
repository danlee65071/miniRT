/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 07:19:36 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 07:19:38 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

/*Инициализация параметров*/
void	init_scene(t_scene *scene)
{
	scene->win_width = 700;
	scene->win_height = 700;
	scene->aspect_ratio = scene->win_width / scene->win_height;
	scene->projection_plane_d = 1;
	scene->view_port_width = 1;
	scene->view_port_height = (scene->view_port_width / scene->aspect_ratio);
	scene->ambient.quantity = 0;
	scene->camera.quantity = 0;
	scene->light_quantity = 0;
	scene->light = NULL;
	scene->shapes.qnty_spheres = 0;
	scene->shapes.sphere = NULL;
	scene->t_min = 0;
	scene->t_max = MAXFLOAT;
	scene->shapes.qnty_planes = 0;
	scene->shapes.plane = NULL;
	scene->shapes.cylinder = NULL;
	scene->shapes.qnty_cylinders = 0;
	scene->shapes.paraboloid = NULL;
	scene->shapes.qnty_paraboloids = 0;
	scene->qnty_light_source = 0;
	scene->vec_z = init_vector(0, 0, 1);
	scene->qnty_shapes = 0;
}
