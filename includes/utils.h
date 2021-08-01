/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:50:04 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/21 18:50:06 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define ESC_KEY 53

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_decisions
{
	float	t1;
	float	t2;
}	t_decisions;

typedef struct s_coeff
{
	float	k1;
	float	k2;
	float	k3;
}	t_coeff;

void		error_message(char *error_message);
float		ft_atof(char *str);
void		free_two_dimensional_string_array(char **array);
void		check_color(t_rgb *rgb);
void		parse_coordinates(t_vector *vector, char *coordiante_line);
void		assining_color(t_rgb *rgb, int red, int green, int blue);
void		check_orientation_vector(t_vector orientation_vector);
float		scalar_product(t_vector vector1, t_vector vector2);
t_vector	subtraction_vectors(t_vector vec1, t_vector vec2);
t_decisions	solving_quadratic_equation(t_coeff coeff);
int			create_trgb(int t, int r, int g, int b);
float		vector_length(t_vector vector);
void		check_brightness(float brightness);
t_vector	vec_product_num(t_vector vec, float num);
t_vector	sum_vec(t_vector vec1, t_vector vec2);
t_rgb		color_product_num(t_rgb rgb, float num);
t_rgb		color_sum(t_rgb rgb1, t_rgb rgb2);
float		find_angle_vectors(t_vector vec1, t_vector vec2);
t_vector	vector_product(t_vector vec1, t_vector vec2);
t_vector	init_vector(float x, float y, float z);
t_vector	vector_rotation(t_vector p, float angle, t_vector v);
int			is_null_vector(t_vector vector);
t_vector	norm_vector(t_vector vector);
t_rgb		lerp_color(t_rgb rgb1, t_rgb rgb2, float t);
t_rgb		inverse_color(t_rgb rgb);

#endif
