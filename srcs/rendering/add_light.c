/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:04:28 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/29 15:04:29 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	add_light(t_scene *scene, t_light new_light)
{
	t_light	*tmp;
	int		i;

	tmp = scene->light;
	scene->light = malloc(sizeof(t_plane)
			* (scene->light_quantity + 1));
	if (scene->light == NULL)
		error_message("Error: Malloc error!\n");
	i = -1;
	while (++i < scene->light_quantity)
		scene->light[i] = tmp[i];
	scene->light[i].brightness = new_light.brightness;
	scene->light[i].coordinates = new_light.coordinates;
	scene->light[i].rgb = new_light.rgb;
	scene->light[i].ind = new_light.ind;
	if (tmp != NULL)
		free(tmp);
}

t_vector	reflect_ray(t_vector R, t_vector N)
{
	t_vector	res;

	res = vec_product_num(N, 2 * scalar_product(N, R));
	res = subtraction_vectors(res, R);
	return (res);
}

void	compute_shadow(t_scene *scene, t_lightning *l, t_vector N, t_vector P)
{
	l->L = subtraction_vectors(scene->light[l->light_ind].coordinates, P);
	l->N_dot_L = scalar_product(N, l->L);
	l->cpy_scene = *scene;
	l->cpy_scene.camera.view_point = P;
	l->cpy_scene.t_max = 1;
	l->cpy_scene.t_min = EPSILON;
	closest_intersection(&(l->cpy_scene), l->L, &(l->traceray));
}

void	compute_specular(t_scene *scene, t_lightning *l, t_vector N, t_vector V)
{
	l->R = reflect_ray(l->L, N);
	l->R_dot_V = scalar_product(l->R, V);
	if (l->R_dot_V > 0)
		l->brightness.brightness += scene->light[l->light_ind].brightness
			* powf(l->R_dot_V / (vector_length(l->R) * vector_length(V)),
				SPECULAR);
}
