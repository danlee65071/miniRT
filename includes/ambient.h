/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:12:22 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/21 18:12:23 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include "minirt.h"

typedef struct s_ambient
{
	float	lighting;
	t_rgb	rgb;
	int		quantity;
}	t_ambient;

typedef struct s_brightness
{
	float	r;
	float	g;
	float	b;
	float	brightness;
}	t_brightness;

t_rgb	add_brightness(t_rgb rgb, t_brightness brightness);

#endif
