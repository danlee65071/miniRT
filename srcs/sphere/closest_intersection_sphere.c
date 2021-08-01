/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_intersection_sphere.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:47:22 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/28 07:47:23 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	find_decison(t_scene *scene, t_traceray *traceray, float decision,
				t_sphere *sphere);
static void	color_init(t_scene *scene, t_traceray *traceray);

int	closest_intersection_sphere(t_scene *scene, t_decisions *decision,
									  t_traceray *traceray, t_vector D)
{
	int			i;

	i = -1;
	while (++i < scene->shapes.qnty_spheres)
	{
		*decision = intersect_ray_sphere(scene, scene->shapes.sphere[i], D);
		find_decison(scene, traceray, decision->t1, &(scene->shapes.sphere[i]));
		find_decison(scene, traceray, decision->t2, &(scene->shapes.sphere[i]));
	}
	if (traceray->closest_shape == NULL)
		return (i);
	if (traceray->closest_shape->sphere == NULL)
		return (i);
	D = vec_product_num(D, traceray->closest_t);
	traceray->P = sum_vec(scene->camera.view_point, D);
	traceray->N = subtraction_vectors(traceray->P,
			traceray->closest_shape->sphere->center);
	traceray->N = norm_vector(traceray->N);
	traceray->V = vec_product_num(D, -1);
	color_init(scene, traceray);
	return (i);
}

static void	find_decison(t_scene *scene, t_traceray *traceray, float decision,
							t_sphere *sphere)
{
	if (decision > scene->t_min && decision < scene->t_max
		&& decision < traceray->closest_t)
	{
		traceray->closest_t = decision;
		if (traceray->closest_shape == NULL)
			traceray->closest_shape = malloc(sizeof(t_shapes));
		if (traceray->closest_shape == NULL)
			error_message("Error: malloc error!\n");
		traceray->closest_shape->sphere = sphere;
		traceray->closest_shape->plane = NULL;
		traceray->closest_shape->cylinder = NULL;
		traceray->closest_shape->paraboloid = NULL;
	}
}

static void	color_init(t_scene *scene, t_traceray *traceray)
{
	t_rgb		even_color;
	t_rgb		odd_color;
	t_rgb		initial_color;

	initial_color = traceray->closest_shape->sphere->rgb;
	if (traceray->closest_shape->sphere->is_checkerboard)
	{
		even_color = traceray->closest_shape->sphere->rgb;
		odd_color = inverse_color(even_color);
		traceray->closest_shape->sphere->rgb
			= chess_color(traceray, even_color, odd_color,
				traceray->closest_shape->sphere->is_checkerboard);
	}
	traceray->color = add_brightness(traceray->closest_shape->sphere->rgb,
			compute_lightning(scene, traceray->P, traceray->N, traceray->V));
	traceray->closest_shape->sphere->rgb = initial_color;
}
