/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:48:06 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/20 19:48:49 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	init_scene(&scene);
	parser(argc, argv, &scene);
	if (scene.qnty_light_source == 0)
		error_message("Error: No light source!\n");
	scene.mlx = mlx_init();
	scene.mlx_win = mlx_new_window(scene.mlx, scene.win_width, scene.win_height,
			"miniRT");
	scene.img.img = mlx_new_image(scene.mlx, scene.win_width, scene.win_height);
	scene.img.addr = mlx_get_data_addr(scene.img.img, &scene.img.bits_per_pixel,
			&scene.img.line_length, &scene.img.endian);
	rendering(&scene);
	mlx_put_image_to_window(scene.mlx, scene.mlx_win, scene.img.img, 0, 0);
	mlx_hook(scene.mlx_win, 17, 0, close_programm, &scene);
	mlx_hook(scene.mlx_win, 2, 0, keyboard, &scene);
	mlx_loop(scene.mlx);
}
