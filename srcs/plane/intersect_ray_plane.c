/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:16:48 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/28 08:16:49 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_decisions	intersect_ray_plane(t_scene *scene, t_plane plane, t_vector D)
{
	t_decisions	decision;
	t_coeff		coeff;
	t_vector	OC;
	t_vector	N;

	decision.t2 = scene->t_min;
	OC = subtraction_vectors(scene->camera.view_point, plane.coordiantes);
	N = plane.orientation_vector;
	coeff.k1 = scalar_product(OC, N);
	coeff.k2 = scalar_product(D, N);
	if (coeff.k2 == 0)
		decision.t1 = scene->t_min;
	coeff.k3 = 0;
	decision.t1 = -coeff.k1 / coeff.k2;
	return (decision);
}
