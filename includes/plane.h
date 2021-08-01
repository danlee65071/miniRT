/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:28:00 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 14:28:01 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "minirt.h"

typedef struct s_plane
{
	t_vector	coordiantes;
	t_vector	orientation_vector;
	t_rgb		rgb;
	int			ind;
	float		is_checkerboard;
}	t_plane;

#endif
