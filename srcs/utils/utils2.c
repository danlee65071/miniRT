/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:48:58 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/21 20:48:59 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Парсинг координат.*/
void	parse_coordinates(t_vector *vector, char *coordiante_line)
{
	char	**parameters;
	int		quantity_paremeters;

	quantity_paremeters = 0;
	parameters = ft_split(coordiante_line, ',');
	while (parameters[quantity_paremeters] != NULL)
		quantity_paremeters++;
	if (quantity_paremeters != 3)
		error_message("Error: Wrong number coordination variable!\n");
	vector->x = ft_atof(parameters[0]);
	vector->y = ft_atof(parameters[1]);
	vector->z = ft_atof(parameters[2]);
	free_two_dimensional_string_array(parameters);
}

/*Проверка ориентационного вектора. Его компоненты не могут быть больше 1 и
 * меньше -1.*/
void	check_orientation_vector(t_vector orientation_vector)
{
	if (orientation_vector.x < -1 || orientation_vector.x > 1)
		error_message("Error: Wrong x parameter of orientation vector!\n");
	if (orientation_vector.y < -1 || orientation_vector.y > 1)
		error_message("Error: Wrong y parameter of orientation vector!\n");
	if (orientation_vector.z < -1 || orientation_vector.z > 1)
		error_message("Error: Wrong z parameter of orientation vector!\n");
}

/*Закрытие программы, очищение всех фигур.*/
int	close_programm(t_scene *scene)
{
	if (scene->shapes.sphere != NULL)
		free(scene->shapes.sphere);
	if (scene->shapes.plane != NULL)
		free(scene->shapes.plane);
	if (scene->shapes.cylinder != NULL)
		free(scene->shapes.cylinder);
	if (scene->shapes.paraboloid != NULL)
		free(scene->shapes.paraboloid);
	mlx_destroy_window(scene->mlx, scene->mlx_win);
	exit (0);
}

/*Вычисление вектора направления луча исходящий из камеры.*/
t_vector	beam_direction(t_scene *scene, int x, int y)
{
	t_vector	beam;

	beam.x = (float)x * (float)scene->view_port_width / (float)scene->win_width;
	beam.y = (float)y * (float)scene->view_port_height
		/ (float)scene->win_height;
	beam.z = scene->projection_plane_d;
	return (beam);
}

/*Решение квадратного уравнения.*/
t_decisions	solving_quadratic_equation(t_coeff coeff)
{
	t_decisions	decision;
	float		discriminant;

	discriminant = coeff.k2 * coeff.k2 - 4 * coeff.k1 * coeff.k3;
	if (discriminant < 0)
	{
		decision.t1 = MAXFLOAT;
		decision.t2 = MAXFLOAT;
		return (decision);
	}
	decision.t1 = (-coeff.k2 + sqrtf(discriminant)) / (2 * coeff.k1);
	decision.t2 = (-coeff.k2 - sqrtf(discriminant)) / (2 * coeff.k1);
	return (decision);
}
