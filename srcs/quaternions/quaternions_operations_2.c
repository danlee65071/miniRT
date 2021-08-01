/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions_operations_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 09:56:38 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/26 09:56:40 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Сопряженное число кватерниона*/
t_quaternions	conjugate_quaternion(t_quaternions q)
{
	t_quaternions	res;

	res.scalar = q.scalar;
	res.vector = vec_product_num(q.vector, -1);
	return (res);
}

/*Модуль кватерниона*/
float	magnitude_quaternion(t_quaternions q)
{
	float	res;

	res = sqrtf(q.scalar * q.scalar + powf(q.vector.x, 2)
			+ powf(q.vector.y, 2) + powf(q.vector.z, 2));
	return (res);
}

/*Обратный кватернион*/
t_quaternions	inverse_quaternion(t_quaternions q)
{
	t_quaternions	res;

	res = conjugate_quaternion(q);
	res = quaternion_product_num(res, 1 / powf(magnitude_quaternion(q), 2));
	return (res);
}

/*Преобразование вектора в кватернион*/
t_quaternions	from_vec_to_quaternion(t_vector v)
{
	t_quaternions	res;

	res.scalar = 0;
	res.vector = v;
	return (res);
}
