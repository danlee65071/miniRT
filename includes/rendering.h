/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:11:34 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/28 06:11:35 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "minirt.h"

typedef struct s_rendering
{
	int			x;
	int			y;
	t_vector	D;
	t_rgb		color;
	float		angle;
	t_vector	rotation_axis;
}	t_rendering;

#endif
