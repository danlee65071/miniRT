/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_intersection_plane.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:05:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/28 08:05:46 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	color_init(t_scene *scene, t_traceray *traceray);
static void	decision_init(t_scene *scene, t_traceray *traceray, float decision,
				t_plane *plane);

int	closest_intersection_plane(t_scene *scene, t_decisions *decision,
								  t_traceray *traceray, t_vector D)
{
	int			i;

	i = -1;
	while (++i < scene->shapes.qnty_planes)
	{
		*decision = intersect_ray_plane(scene, scene->shapes.plane[i], D);
		decision_init(scene, traceray, decision->t1, &(scene->shapes.plane[i]));
	}
	if (traceray->closest_shape == NULL)
		return (i);
	if (traceray->closest_shape->plane == NULL)
		return (i);
	D = vec_product_num(D, traceray->closest_t);
	traceray->P = sum_vec(scene->camera.view_point, D);
	traceray->N = traceray->closest_shape->plane->orientation_vector;
	traceray->N = norm_vector(traceray->N);
	traceray->V = vec_product_num(D, -1);
	color_init(scene, traceray);
	return (i);
}

static void	color_init(t_scene *scene, t_traceray *traceray)
{
	t_rgb		even_color;
	t_rgb		odd_color;
	t_rgb		initial_color;

	initial_color = traceray->closest_shape->plane->rgb;
	if (traceray->closest_shape->plane->is_checkerboard)
	{
		even_color = traceray->closest_shape->plane->rgb;
		odd_color = inverse_color(even_color);
		traceray->closest_shape->plane->rgb
			= chess_color(traceray, even_color, odd_color,
				traceray->closest_shape->plane->is_checkerboard);
	}
	traceray->color = add_brightness(traceray->closest_shape->plane->rgb,
			compute_lightning(scene, traceray->P, traceray->N, traceray->V));
	traceray->closest_shape->plane->rgb = initial_color;
}

static void	decision_init(t_scene *scene, t_traceray *traceray, float decision,
							 t_plane *plane)
{
	if (decision > scene->t_min && decision < scene->t_max
		&& decision < traceray->closest_t)
	{
		traceray->closest_t = decision;
		if (traceray->closest_shape == NULL)
			traceray->closest_shape = malloc(sizeof(t_shapes));
		if (traceray->closest_shape == NULL)
			error_message("Error: malloc error!\n");
		traceray->closest_shape->plane = plane;
		traceray->closest_shape->sphere = NULL;
		traceray->closest_shape->cylinder = NULL;
		traceray->closest_shape->paraboloid = NULL;
	}
}
