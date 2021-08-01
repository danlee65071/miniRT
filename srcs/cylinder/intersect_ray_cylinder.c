/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:26:04 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/28 14:26:05 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Пересечение луча с цилиндром.
 * Функция возвращает элемент структуры t_decisions, в которой лежат две
 * скалярные величины. Умножение вектора направления луча на скалярную
 * величину дает точку перечечения луча с цилиндром.*/
t_decisions	intersect_ray_cylinder(t_scene *scene, t_cylinder cylinder,
									t_vector D)
{
	t_decisions	decision;
	t_coeff		coeff;
	t_vector	OC;

	OC = subtraction_vectors(scene->camera.view_point, cylinder.coordinates);
	cylinder.orientation_vector = norm_vector(cylinder.orientation_vector);
	coeff.k1 = scalar_product(D, D)
		- powf(scalar_product(D, cylinder.orientation_vector), 2);
	coeff.k2 = 2 * (scalar_product(D, OC)
			- scalar_product(OC, cylinder.orientation_vector)
			* scalar_product(D, cylinder.orientation_vector));
	coeff.k3 = scalar_product(OC, OC)
		- powf(scalar_product(OC, cylinder.orientation_vector), 2)
		- powf(cylinder.diameter / 2, 2);
	decision = solving_quadratic_equation(coeff);
	return (decision);
}
