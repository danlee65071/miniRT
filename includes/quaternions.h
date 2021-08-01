/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:43:11 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/25 15:43:13 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNIONS_H
# define QUATERNIONS_H

# include "minirt.h"

typedef struct s_quaternions
{
	float		scalar;
	t_vector	vector;
}	t_quaternions;

void			quaternion_init(t_quaternions *q, float scalar,
					t_vector vector);
t_quaternions	sum_quaternions(t_quaternions q1, t_quaternions q2);
t_quaternions	subtraction_quaternions(t_quaternions q1, t_quaternions q2);
t_quaternions	product_quaternions(t_quaternions q1, t_quaternions q2);
t_quaternions	quaternion_product_num(t_quaternions q, float num);
t_quaternions	conjugate_quaternion(t_quaternions q);
float			magnitude_quaternion(t_quaternions q);;
t_quaternions	inverse_quaternion(t_quaternions q);
t_quaternions	from_vec_to_quaternion(t_vector v);

#endif
