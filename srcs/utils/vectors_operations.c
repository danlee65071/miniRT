/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 07:32:22 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/24 07:32:23 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Скалярная произведение векторов*/
float	scalar_product(t_vector vector1, t_vector vector2)
{
	return (vector1.x * vector2.x + vector1.y * vector2.y
		+ vector1.z * vector2.z);
}

/*Разность векторов*/
t_vector	subtraction_vectors(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res.x = vec1.x - vec2.x;
	res.y = vec1.y - vec2.y;
	res.z = vec1.z - vec2.z;
	return (res);
}

/*Длина вектора*/
float	vector_length(t_vector vector)
{
	return (sqrtf(vector.x * vector.x + vector.y * vector.y
			+ vector.z * vector.z));
}

/*Умножение константы на вектор*/
t_vector	vec_product_num(t_vector vec, float num)
{
	t_vector	res;

	res.x = vec.x * num;
	res.y = vec.y * num;
	res.z = vec.z * num;
	return (res);
}

/*Сумма векторов*/
t_vector	sum_vec(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res.x = vec1.x + vec2.x;
	res.y = vec1.y + vec2.y;
	res.z = vec1.z + vec2.z;
	return (res);
}
