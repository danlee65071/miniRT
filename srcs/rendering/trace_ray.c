/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:03:34 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/28 08:03:36 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	trace_ray(t_scene *scene, t_vector D, int depth)
{
	t_traceray	traceray;

	closest_intersection(scene, D, &traceray);
	if (traceray.closest_shape == NULL)
	{
		assining_color(&(traceray.color), 0, 0, 0);
		return (traceray.color);
	}
	if (depth <= 0)
		return (traceray.color);
	traceray.R = reflect_ray(traceray.V, traceray.N);
	traceray.cpy_scene = *scene;
	traceray.cpy_scene.camera.view_point = traceray.P;
	traceray.cpy_scene.t_min = EPSILON;
	traceray.cpy_scene.t_max = MAXFLOAT;
	traceray.reflected_color
		= trace_ray(&traceray.cpy_scene, traceray.R, depth - 1);
	traceray.color
		= color_product_num(traceray.color, 1 - REFLECTIVE);
	traceray.reflected_color
		= color_product_num(traceray.reflected_color, REFLECTIVE);
	traceray.color = color_sum(traceray.color, traceray.reflected_color);
	return (traceray.color);
}
