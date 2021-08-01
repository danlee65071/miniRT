/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chess_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 09:13:22 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/31 09:13:28 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	chess_color(t_traceray *traceray, t_rgb even_color, t_rgb odd_color,
					 float scale_cell)
{
	float		chessboard;
	float		tmp;
	t_vector	tmp_p;
	t_rgb		res;

	tmp_p = traceray->P;
	tmp_p = vec_product_num(tmp_p, 1 / scale_cell);
	tmp_p.x = floorf(tmp_p.x);
	tmp_p.y = floorf(tmp_p.y);
	tmp_p.z = floorf(tmp_p.z);
	chessboard = tmp_p.x + tmp_p.y + tmp_p.z;
	chessboard = modff(chessboard * 0.5, &tmp);
	chessboard *= 2;
	chessboard = fabsf(chessboard);
	res = lerp_color(even_color, odd_color, chessboard);
	return (res);
}
