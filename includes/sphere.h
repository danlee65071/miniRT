/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 09:09:24 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 09:09:27 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "minirt.h"

typedef struct s_sphere
{
	t_vector	center;
	float		diameter;
	t_rgb		rgb;
	int			ind;
	float		is_checkerboard;
}	t_sphere;

#endif
