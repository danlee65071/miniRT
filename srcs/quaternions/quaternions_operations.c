/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:43:34 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/25 15:43:36 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Инициализация кватерниона*/
void	quaternion_init(t_quaternions *q, float scalar, t_vector vector)
{
	q->scalar = scalar;
	q->vector = vector;
}

/*Сложение кватернионов*/
t_quaternions	sum_quaternions(t_quaternions q1, t_quaternions q2)
{
	t_quaternions	res;

	res.scalar = q1.scalar + q2.scalar;
	res.vector = sum_vec(q1.vector, q2.vector);
	return (res);
}

/*Разность кватернионов q1 - q2*/
t_quaternions	subtraction_quaternions(t_quaternions q1, t_quaternions q2)
{
	t_quaternions	res;

	res.scalar = q1.scalar - q2.scalar;
	res.vector = subtraction_vectors(q1.vector, q2.vector);
	return (res);
}

/*Произведение кватернионов*/
t_quaternions	product_quaternions(t_quaternions q1, t_quaternions q2)
{
	t_quaternions	res;
	t_vector		a;
	t_vector		b;
	t_vector		q1_vec_sum_q2_vec;

	res.scalar = q1.scalar * q2.scalar - scalar_product(q1.vector, q2.vector);
	a = vec_product_num(q1.vector, q2.scalar);
	b = vec_product_num(q2.vector, q1.scalar);
	q1_vec_sum_q2_vec = sum_vec(a, b);
	res.vector = sum_vec(q1_vec_sum_q2_vec,
			vector_product(q1.vector, q2.vector));
	return (res);
}

/*Произведение кватерниона на число*/
t_quaternions	quaternion_product_num(t_quaternions q, float num)
{
	t_quaternions	res;

	res.scalar = q.scalar * num;
	res.vector = vec_product_num(q.vector, num);
	return (res);
}
