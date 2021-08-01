/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:59:29 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/30 09:59:31 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARABOLOID_H
# define PARABOLOID_H

# include "minirt.h"

typedef struct s_paraboloid
{
	t_vector	extremum;
	t_vector	orientation_vector;
	float		dist_to_kernel;
	t_rgb		rgb;
	int			ind;
	float		is_checkerboard;
}	t_paraboloid;

#endif
