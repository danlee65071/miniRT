/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 09:22:53 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/24 09:22:55 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	closest_intersection(t_scene *scene, t_vector D, t_traceray *traceray)
{
	int			i;
	t_decisions	decision;

	traceray->closest_t = MAXFLOAT;
	traceray->closest_shape = NULL;
	i = 0;
	while (i < scene->qnty_shapes)
	{
		i += closest_intersection_sphere(scene, &decision, traceray, D);
		i += closest_intersection_plane(scene, &decision, traceray, D);
		i += closest_intersection_cylinder(scene, &decision, traceray, D);
		i += closest_intersection_paraboloid(scene, &decision, traceray, D);
	}
	if (traceray->closest_shape != NULL)
		free(traceray->closest_shape);
}
