/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:19:23 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/20 19:21:24 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "utils.h"
# include "ambient.h"
# include "camera.h"
# include "light.h"
# include "sphere.h"
# include "plane.h"
# include "cylinder.h"
# include "paraboloid.h"
# include "shapes.h"
# include "parser.h"
# include "quaternions.h"
# include "rendering.h"

# define SPECULAR 1000
# define EPSILON 0.1
# define REFLECTIVE 0.4
# define RECURSION_DEPTH 3

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		*light;
	int			qnty_light_source;
	int			light_quantity;
	t_shapes	shapes;
	int			qnty_shapes;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	int			win_width;
	int			win_height;
	float		projection_plane_d;
	float		view_port_width;
	float		view_port_height;
	float		t_min;
	float		t_max;
	float		aspect_ratio;
	t_vector	vec_z;
}	t_scene;

typedef struct s_traceray
{
	t_rgb		color;
	float		closest_t;
	t_shapes	*closest_shape;
	t_vector	P;
	t_vector	N;
	t_vector	V;
	t_vector	R;
	t_rgb		reflected_color;
	t_scene		cpy_scene;
}	t_traceray;

typedef struct s_closest_cy
{
	t_scene		*scene;
	t_decisions	*decision;
	t_inter_cy	t;
	t_traceray	*traceray;
	t_vector	D;
}	t_closest_cy;

typedef struct s_lightning
{
	t_brightness	brightness;
	int				i;
	t_vector		L;
	float			N_dot_L;
	t_vector		R;
	float			R_dot_V;
	int				is_add_ambient;
	t_scene			cpy_scene;
	t_traceray		traceray;
	int				light_ind;
}	t_lightning;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			parser(int argc, char **argv, t_scene *scene);
void			parse_ambient(t_scene *scene, char **parameters);
void			init_scene(t_scene *scene);
void			parse_camera(t_scene *scene, char **parameters);
void			parse_light(t_scene *scene, char **parameters);
void			add_sphere(t_scene *scene, t_sphere sphere_parameters);
void			parse_sphere(t_scene *scene, char **parameters);
void			add_plane(t_scene *scene, t_plane new_plane_parameters);
void			parse_plane(t_scene *scene, char **parameters);
void			parse_cylinder(t_scene *scene, char **parameters);
void			add_cylinder(t_scene *scene,
					t_cylinder new_cylinder_parameters);
void			add_light(t_scene *scene, t_light new_light);
int				close_programm(t_scene *scene);
int				keyboard(int keycode, t_scene *scene);
t_vector		beam_direction(t_scene *scene, int x, int y);
t_decisions		intersect_ray_sphere(t_scene *scene, t_sphere sphere,
					t_vector D);
t_rgb			trace_ray(t_scene *scene, t_vector D, int depth);
void			rendering(t_scene *scene);
t_brightness	compute_lightning(t_scene *scene, t_vector P, t_vector N,
					t_vector V);
void			closest_intersection(t_scene *scene, t_vector D,
					t_traceray *traceray);
t_vector		reflect_ray(t_vector R, t_vector N);
int				closest_intersection_sphere(t_scene *scene,
					t_decisions *decision, t_traceray *traceray, t_vector D);
t_decisions		intersect_ray_plane(t_scene *scene, t_plane plane, t_vector D);
int				closest_intersection_plane(t_scene *scene,
					t_decisions *decision, t_traceray *traceray, t_vector D);
t_decisions		intersect_ray_cylinder(t_scene *scene, t_cylinder cylinder,
					t_vector D);
int				closest_intersection_cylinder(t_scene *scene,
					t_decisions *decision, t_traceray *traceray, t_vector D);
void			add_paraboloid(t_scene *scene,
					t_paraboloid new_paraboloid_parameters);
void			parse_paraboloid(t_scene *scene, char **parameters);
t_decisions		intersect_ray_paraboloid(t_scene *scene,
					t_paraboloid paraboloid, t_vector D);
int				closest_intersection_paraboloid(t_scene *scene,
					t_decisions *decision, t_traceray *traceray, t_vector D);
t_rgb			chess_color(t_traceray *traceray, t_rgb even_color,
					t_rgb odd_color, float scale_cell);
void			compute_shadow(t_scene *scene, t_lightning *l, t_vector N,
					t_vector P);
void			compute_specular(t_scene *scene, t_lightning *l, t_vector N,
					t_vector V);

#endif
