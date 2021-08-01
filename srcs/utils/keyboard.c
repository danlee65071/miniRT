/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:42:12 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/07/22 18:42:14 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*Обработка нажатия на ESC*/
int	keyboard(int keycode, t_scene *scene)
{
	if (keycode == ESC_KEY)
		close_programm(scene);
	return (0);
}
