/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_paraboloid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:39:48 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/30 09:39:49 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_decisions	intersect_ray_paraboloid(t_scene *scene, t_paraboloid paraboloid,
										t_vector D)
{
	t_decisions	decision;
	t_coeff		coeff;
	t_vector	OC;

	paraboloid.orientation_vector = norm_vector(paraboloid.orientation_vector);
	OC = subtraction_vectors(scene->camera.view_point, paraboloid.extremum);
	coeff.k1 = scalar_product(D, D)
		- powf(scalar_product(D, paraboloid.orientation_vector), 2);
	coeff.k2 = 2 * (scalar_product(OC, D)
			- scalar_product(D, paraboloid.orientation_vector)
			* (scalar_product(OC, paraboloid.orientation_vector) + 2
				* paraboloid.dist_to_kernel));
	coeff.k3 = scalar_product(OC, OC)
		- scalar_product(OC, paraboloid.orientation_vector)
		* (scalar_product(OC, paraboloid.orientation_vector) + 4
			* paraboloid.dist_to_kernel);
	decision = solving_quadratic_equation(coeff);
	return (decision);
}
