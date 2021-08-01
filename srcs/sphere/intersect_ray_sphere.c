/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 06:10:03 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/23 06:10:08 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_decisions	intersect_ray_sphere(t_scene *scene, t_sphere sphere, t_vector D)
{
	t_decisions	decision;
	t_coeff		coeff;
	t_vector	OC;

	OC = subtraction_vectors(scene->camera.view_point, sphere.center);
	coeff.k1 = scalar_product(D, D);
	coeff.k2 = 2 * scalar_product(OC, D);
	coeff.k3 = scalar_product(OC, OC) - (sphere.diameter / 2)
		* (sphere.diameter / 2);
	decision = solving_quadratic_equation(coeff);
	return (decision);
}
