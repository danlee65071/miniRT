/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:34:54 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/21 18:34:56 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "minirt.h"

typedef struct s_camera
{
	t_vector	view_point;
	t_vector	orientation_vector;
	float		fov;
	int			quantity;
}	t_camera;

#endif
