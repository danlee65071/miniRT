/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_operations_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:18:49 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/26 18:18:50 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Нормализация вектора*/
t_vector	norm_vector(t_vector vector)
{
	t_vector	res;
	float		len_vec;

	len_vec = vector_length(vector);
	res.x = vector.x / len_vec;
	res.y = vector.y / len_vec;
	res.z = vector.z / len_vec;
	return (res);
}
