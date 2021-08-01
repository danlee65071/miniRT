/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:56:12 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/21 18:56:14 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "minirt.h"

typedef struct s_light
{
	t_vector	coordinates;
	float		brightness;
	t_rgb		rgb;
	int			ind;
}	t_light;

#endif
