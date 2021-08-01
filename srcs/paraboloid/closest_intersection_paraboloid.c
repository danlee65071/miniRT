/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_intersection_paraboloid.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:39:30 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/30 09:39:31 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	decision_init(t_scene *scene, t_traceray *traceray, float decision,
				t_paraboloid *paraboloid);
static void	color_init(t_scene *scene, t_traceray *traceray);
static void	vectors_init(t_scene *scene, t_traceray *traceray, t_vector D);

int	closest_intersection_paraboloid(t_scene *scene, t_decisions *decision,
								   t_traceray *traceray, t_vector D)
{
	int			i;

	i = -1;
	while (++i < scene->shapes.qnty_paraboloids)
	{
		*decision = intersect_ray_paraboloid(scene,
				scene->shapes.paraboloid[i], D);
		decision_init(scene, traceray, decision->t1,
			&(scene->shapes.paraboloid[i]));
		decision_init(scene, traceray, decision->t2,
			&(scene->shapes.paraboloid[i]));
	}
	if (traceray->closest_shape == NULL)
		return (i);
	if (traceray->closest_shape->paraboloid == NULL)
		return (i);
	vectors_init(scene, traceray, D);
	color_init(scene, traceray);
	return (i);
}

static void	decision_init(t_scene *scene, t_traceray *traceray, float decision,
							 t_paraboloid *paraboloid)
{
	if (decision > scene->t_min && decision < scene->t_max
		&& decision < traceray->closest_t)
	{
		traceray->closest_t = decision;
		if (traceray->closest_shape == NULL)
			traceray->closest_shape = malloc(sizeof(t_shapes));
		if (traceray->closest_shape == NULL)
			error_message("Error: malloc error!\n");
		traceray->closest_shape->paraboloid = paraboloid;
		traceray->closest_shape->plane = NULL;
		traceray->closest_shape->cylinder = NULL;
		traceray->closest_shape->sphere = NULL;
	}
}

static void	color_init(t_scene *scene, t_traceray *traceray)
{
	t_rgb		even_color;
	t_rgb		odd_color;
	t_rgb		initial_color;

	initial_color = traceray->closest_shape->paraboloid->rgb;
	if (traceray->closest_shape->paraboloid->is_checkerboard)
	{
		even_color = traceray->closest_shape->paraboloid->rgb;
		odd_color = inverse_color(even_color);
		traceray->closest_shape->paraboloid->rgb
			= chess_color(traceray, even_color, odd_color,
				traceray->closest_shape->paraboloid->is_checkerboard);
	}
	traceray->color = add_brightness(traceray->closest_shape->paraboloid->rgb,
			compute_lightning(scene, traceray->P, traceray->N, traceray->V));
	traceray->closest_shape->paraboloid->rgb = initial_color;
}

static void	vectors_init(t_scene *scene, t_traceray *traceray, t_vector D)
{
	float		m;

	D = vec_product_num(D, traceray->closest_t);
	traceray->P = sum_vec(scene->camera.view_point, D);
	m = scalar_product(subtraction_vectors(traceray->P,
				traceray->closest_shape->paraboloid->extremum),
			traceray->closest_shape->paraboloid->orientation_vector);
	traceray->N = subtraction_vectors(traceray->P,
			traceray->closest_shape->paraboloid->extremum);
	traceray->N = subtraction_vectors(traceray->N, vec_product_num
			(traceray->closest_shape->paraboloid->orientation_vector, m
				+ traceray->closest_shape->paraboloid->dist_to_kernel));
	traceray->N = norm_vector(traceray->N);
	traceray->V = vec_product_num(D, -1);
}
