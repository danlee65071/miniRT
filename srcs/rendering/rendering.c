/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:49:09 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/27 18:49:11 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	camera_orientation(t_scene *scene, t_rendering *rendering);

void	rendering(t_scene *scene)
{
	t_rendering	rendering;

	if (scene->camera.quantity < 1)
		error_message("Error: There is no camera in the scene1\n");
	camera_orientation(scene, &rendering);
	rendering.x = -scene->win_width / 2 + 1;
	while (rendering.x < scene->win_width / 2)
	{
		rendering.y = -scene->win_height / 2 + 1;
		while (rendering.y < scene->win_height / 2)
		{
			rendering.D = beam_direction(scene, rendering.x, rendering.y);
			rendering.D = vector_rotation(rendering.D, rendering.angle,
					rendering.rotation_axis);
			rendering.color = trace_ray(scene, rendering.D, RECURSION_DEPTH);
			my_mlx_pixel_put(&(scene->img), rendering.x
				+ scene->win_width / 2,
				scene->win_height / 2 - rendering.y,
				create_trgb(0, rendering.color.r,
					rendering.color.g, rendering.color.b));
			rendering.y++;
		}
		rendering.x++;
	}
}

static void	camera_orientation(t_scene *scene, t_rendering *rendering)
{
	rendering->angle = find_angle_vectors(scene->camera.orientation_vector,
			scene->vec_z);
	rendering->rotation_axis = vector_product(scene->vec_z,
			scene->camera.orientation_vector);
	if (is_null_vector(rendering->rotation_axis) == 1)
		rendering->rotation_axis = init_vector(0, 1, 0);
	rendering->rotation_axis = norm_vector(rendering->rotation_axis);
}
