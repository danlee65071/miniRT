/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:37:37 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/20 20:37:39 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	check_format_file(char *file_name);
static void	parsing_from_file(t_scene *scene, int fd);
static void	processing_parameters(t_scene *scene, char *line);

/*Начало парсинга данных.*/
void	parser(int argc, char **argv, t_scene *scene)
{
	int	fd;

	if (argc != 2)
		error_message("Error: Wrong number of arguments!\n");
	check_format_file(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message("Error: No such file!\n");
	parsing_from_file(scene, fd);
}

/*Проверка формата файла с данными.*/
static void	check_format_file(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i] != '.' && file_name[i] != '\0')
		i++;
	if (file_name[i] == '.')
	{
		if (ft_strncmp(file_name + i, ".rt", 4) == 0)
			return ;
	}
	error_message("Error: file format is wrong!\n");
}

/*Парсинг данных с файла.*/
static void	parsing_from_file(t_scene *scene, int fd)
{
	char	*line;

	while (get_next_line(fd, &line) != 0)
		processing_parameters(scene, line);
	processing_parameters(scene, line);
}

/*Парсинг данных в объекты.*/
static void	processing_parameters(t_scene *scene, char *line)
{
	char	**parameters;

	parameters = ft_split(line, ' ');
	if (*parameters != NULL)
	{
		if (ft_strncmp(parameters[0], "A", ft_strlen(parameters[0])) == 0)
			parse_ambient(scene, parameters);
		else if (ft_strncmp(parameters[0], "C", ft_strlen(parameters[0])) == 0)
			parse_camera(scene, parameters);
		else if (ft_strncmp(parameters[0], "L", ft_strlen(parameters[0])) == 0)
			parse_light(scene, parameters);
		else if (ft_strncmp(parameters[0], "sp", ft_strlen(parameters[0])) == 0)
			parse_sphere(scene, parameters);
		else if (ft_strncmp(parameters[0], "pl", ft_strlen(parameters[0])) == 0)
			parse_plane(scene, parameters);
		else if (ft_strncmp(parameters[0], "cy", ft_strlen(parameters[0])) == 0)
			parse_cylinder(scene, parameters);
		else if (ft_strncmp(parameters[0], "pa", ft_strlen(parameters[0])) == 0)
			parse_paraboloid(scene, parameters);
		else
			error_message("Error: Unknown object!\n");
	}
	free(line);
	free_two_dimensional_string_array(parameters);
}
