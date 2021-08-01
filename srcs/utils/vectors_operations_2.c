/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_operations_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:29:16 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/25 15:29:18 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Инициализация вектора*/
t_vector	init_vector(float x, float y, float z)
{
	t_vector	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

/*Нахождение угла между векторами*/
float	find_angle_vectors(t_vector vec1, t_vector vec2)
{
	float	angle;

	angle = acosf(scalar_product(vec1, vec2) / (vector_length(vec1)
				* vector_length(vec2)));
	return (angle);
}

/*Векторное умножение в левом ортонормированном базисе*/
t_vector	vector_product(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res.x = vec1.z * vec2.y - vec1.y * vec2.z;
	res.y = vec1.x * vec2.z - vec1.z * vec2.x;
	res.z = vec1.y * vec2.x - vec1.x * vec2.y;
	return (res);
}

/*Поворот вектора p на угол angle относительно оси (вектора) v*/
t_vector	vector_rotation(t_vector p, float angle, t_vector v)
{
	t_vector		res;
	t_quaternions	q;
	t_quaternions	inverse_q;

	quaternion_init(&q, cosf(angle / 2), vec_product_num(v, sinf(angle / 2)));
	inverse_q = inverse_quaternion(q);
	q = product_quaternions(q, from_vec_to_quaternion(p));
	q = product_quaternions(q, inverse_q);
	res = q.vector;
	return (res);
}

/*Проверка на 0 вектор*/
int	is_null_vector(t_vector vector)
{
	if (vector.x == 0 && vector.y == 0 && vector.z == 0)
		return (1);
	return (0);
}
