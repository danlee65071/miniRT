/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:21:00 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 16:23:45 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "minirt.h"

typedef struct s_cylinder
{
	t_vector	coordinates;
	t_vector	orientation_vector;
	float		diameter;
	float		height;
	t_rgb		rgb;
	int			ind;
	float		is_checkerboard;
}	t_cylinder;

typedef struct s_inter_cy
{
	int			i;
	float		m;
	t_vector	OC;
	t_rgb		even_color;
	t_rgb		odd_color;
	t_rgb		initial_color;
	t_vector	D;
}	t_inter_cy;

#endif
