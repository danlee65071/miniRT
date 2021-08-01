/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:06:04 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/21 19:06:05 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "minirt.h"

typedef struct s_shapes
{
	t_sphere		*sphere;
	int				qnty_spheres;
	t_plane			*plane;
	int				qnty_planes;
	t_cylinder		*cylinder;
	int				qnty_cylinders;
	t_paraboloid	*paraboloid;
	int				qnty_paraboloids;
}	t_shapes;

#endif
