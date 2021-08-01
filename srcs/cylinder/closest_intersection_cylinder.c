/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_intersection_cylinder.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:25:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/28 14:25:45 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	cylinder_init(t_scene *scene, t_traceray *traceray, t_inter_cy *t,
				float decision);
static void	color_init(t_scene *scene, t_traceray *traceray, t_inter_cy t);
static void	vectors_init(t_scene *scene, t_traceray *traceray, t_inter_cy t);

/*Нахождение ближащего цилиндра.*/
int	closest_intersection_cylinder(t_scene *scene, t_decisions *decision,
								  t_traceray *traceray, t_vector D)
{
	t_inter_cy	t;

	t.D = D;
	t.i = -1;
	while (++t.i < scene->shapes.qnty_cylinders)
	{
		*decision = intersect_ray_cylinder(scene,
				scene->shapes.cylinder[t.i], D);
		t.OC = subtraction_vectors(scene->camera.view_point,
				scene->shapes.cylinder[t.i].coordinates);
		if (decision->t1 > scene->t_min && decision->t1 < scene->t_max
			&& decision->t1 < traceray->closest_t)
			cylinder_init(scene, traceray, &t, decision->t1);
		if (decision->t2 > scene->t_min && decision->t2 < scene->t_max
			&& decision->t2 < traceray->closest_t)
			cylinder_init(scene, traceray, &t, decision->t2);
	}
	if (traceray->closest_shape == NULL)
		return (t.i);
	if (traceray->closest_shape->cylinder == NULL)
		return (t.i);
	vectors_init(scene, traceray, t);
	return (t.i);
}

/*Нахождение ближащего цилиндра.*/
static void	cylinder_init(t_scene *scene, t_traceray *traceray, t_inter_cy *t,
							 float decision)
{
	t->m = scalar_product(t->OC,
			scene->shapes.cylinder[t->i].orientation_vector)
		+ decision * scalar_product(t->D,
			scene->shapes.cylinder[t->i].orientation_vector);
	if (t->m > 0 && t->m < scene->shapes.cylinder[t->i].height)
	{
		traceray->closest_t = decision;
		if (traceray->closest_shape == NULL)
			traceray->closest_shape = malloc(sizeof(t_shapes));
		if (traceray->closest_shape == NULL)
			error_message("Error: malloc error!\n");
		traceray->closest_shape->cylinder
			= &(scene->shapes.cylinder[t->i]);
		traceray->closest_shape->sphere = NULL;
		traceray->closest_shape->plane = NULL;
		traceray->closest_shape->paraboloid = NULL;
	}
}

/*Определение цвета ближащего цилиндра.*/
static void	color_init(t_scene *scene, t_traceray *traceray, t_inter_cy t)
{
	t.initial_color = traceray->closest_shape->cylinder->rgb;
	if (traceray->closest_shape->cylinder->is_checkerboard)
	{
		t.even_color = traceray->closest_shape->cylinder->rgb;
		t.odd_color = inverse_color(t.even_color);
		traceray->closest_shape->cylinder->rgb
			= chess_color(traceray, t.even_color, t.odd_color,
				traceray->closest_shape->cylinder->is_checkerboard);
	}
	traceray->color = add_brightness(traceray->closest_shape->cylinder->rgb,
			compute_lightning(scene, traceray->P, traceray->N, traceray->V));
	traceray->closest_shape->cylinder->rgb = t.initial_color;
}

/*Определение основных веторов и ближайщей точки пересечения цилиндра с лучом*/
static void	vectors_init(t_scene *scene, t_traceray *traceray, t_inter_cy t)
{
	traceray->closest_shape->cylinder->orientation_vector
		= norm_vector(traceray->closest_shape->cylinder->orientation_vector);
	t.D = vec_product_num(t.D, traceray->closest_t);
	traceray->P = sum_vec(scene->camera.view_point, t.D);
	traceray->closest_shape->cylinder->orientation_vector
		= norm_vector(traceray->closest_shape->cylinder->orientation_vector);
	traceray->N = subtraction_vectors(traceray->P,
			traceray->closest_shape->cylinder->coordinates);
	traceray->N = subtraction_vectors(traceray->N,
			vec_product_num(traceray->closest_shape->cylinder
				->orientation_vector, t.m));
	traceray->N = norm_vector(traceray->N);
	traceray->V = vec_product_num(t.D, -1);
	color_init(scene, traceray, t);
}
