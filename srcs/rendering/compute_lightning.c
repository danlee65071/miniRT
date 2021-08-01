/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:33:33 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/23 16:33:35 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_param(t_lightning *l);
static void	ambient_proc(t_scene *scene, t_lightning *l);
static void	diffusivity(t_scene *scene, t_lightning *l, t_vector N);
static void	check_brightness_rgb(float *c);

/*Здесь происходит вычисление яркости света.
 * Переменная l.brightness содержит информацию о суммарной яркости и цвета
 * света.
 * l.i - счетчик.
 * l.L - световой вектор для light.
 * N - нормаль к поверхности в точке P.
 * l.R - отраженный от поверхности луч.
 * V - вектор обзора, указывающий от объекта в камеру.
 * l.N_dot_L - скалярное произведение векторов N и l.L.
 * l.R_dot_V - скалярное произведение векторов l.R и V.
 * l.is_add_ambient - переменнвя, служащая для добаления лишь одного ambient.
 * l.cpy_scene - копия переменной scene.
 * shadow_sphere - затенненая сфера.
 * */
t_brightness	compute_lightning(t_scene *scene, t_vector P, t_vector N,
								  t_vector V)
{
	t_lightning	l;

	init_param(&l);
	while (l.i < scene->qnty_light_source)
	{
		ambient_proc(scene, &l);
		if (l.light_ind < scene->light_quantity)
		{
			compute_shadow(scene, &l, N, P);
			if (l.traceray.closest_shape != NULL)
			{
				l.i++;
				l.light_ind++;
				continue ;
			}
			else
				free(l.traceray.closest_shape);
			diffusivity(scene, &l, N);
			compute_specular(scene, &l, N, V);
			l.i++;
			l.light_ind++;
		}
	}
	return (l.brightness);
}

static void	init_param(t_lightning *l)
{
	l->brightness.r = 0;
	l->brightness.g = 0;
	l->brightness.b = 0;
	l->brightness.brightness = 0;
	l->is_add_ambient = 0;
	l->light_ind = 0;
	l->i = 0;
}

static void	ambient_proc(t_scene *scene, t_lightning *l)
{
	if (scene->ambient.quantity == 1 && l->is_add_ambient == 0)
	{
		l->brightness.r += scene->ambient.lighting
			* (float)scene->ambient.rgb.r;
		l->brightness.g += scene->ambient.lighting
			* (float)scene->ambient.rgb.g;
		l->brightness.b += scene->ambient.lighting
			* (float)scene->ambient.rgb.b;
		l->brightness.brightness += scene->ambient.lighting;
		l->is_add_ambient = 1;
		(l->i)++;
	}
}

static void	diffusivity(t_scene *scene, t_lightning *l, t_vector N)
{
	if (l->N_dot_L > 0)
	{
		l->brightness.r += scene->light[l->light_ind].brightness
			* (float)scene->light[l->light_ind].rgb.r;
		check_brightness_rgb(&(l->brightness.r));
		l->brightness.g += scene->light[l->light_ind].brightness
			* (float)scene->light[l->light_ind].rgb.g;
		check_brightness_rgb(&(l->brightness.g));
		l->brightness.b += scene->light[l->light_ind].brightness
			* (float)scene->light[l->light_ind].rgb.b;
		check_brightness_rgb(&(l->brightness.b));
		l->brightness.brightness += scene->light[l->light_ind].brightness
			* l->N_dot_L / (vector_length(N) * vector_length(l->L));
		if (l->brightness.brightness < 0)
			l->brightness.brightness = 0;
		else if (l->brightness.brightness > 1)
			l->brightness.r = 1;
	}
}

static void	check_brightness_rgb(float *c)
{
	if (*c < 0)
		*c = 0;
	else if (*c > 255)
		*c = 255;
}
