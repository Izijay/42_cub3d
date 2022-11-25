/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:04:25 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/06 14:30:14 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_plan(t_data *data)
{
	double	dir;

	dir = data->player_dir;
	if (dir > (5 * M_PI) / 4 && dir < (7 * M_PI) / 4)
	{
		data->rc->plane_x = 0.0;
		data->rc->plane_y = (0.66);
	}
	else if (dir > (7 * M_PI) / 4 || dir < M_PI / 4)
	{
		data->rc->plane_x = 0.66;
		data->rc->plane_y = 0.0;
	}
	else if (dir > M_PI / 4 && dir < (3 * M_PI) / 4)
	{
		data->rc->plane_x = 0.0;
		data->rc->plane_y = (-0.66);
	}
	else if (dir > (3 * M_PI) / 4 && dir < (5 * M_PI) / 4)
	{
		data->rc->plane_x = (-0.66);
		data->rc->plane_y = 0.0;
	}
}

void	init_ray_dir(t_data *data)
{
	double	dir;

	dir = data->player_dir;
	if (dir > (5 * M_PI) / 4 && dir < (7 * M_PI) / 4)
	{
		data->rc->dir_x = (-1.0);
		data->rc->dir_y = 0.0;
	}
	else if (dir > (7 * M_PI) / 4 || dir < M_PI / 4)
	{
		data->rc->dir_x = 0.0;
		data->rc->dir_y = 1.0;
	}
	else if (dir > M_PI / 4 && dir < (3 * M_PI) / 4)
	{
		data->rc->dir_x = 1.0;
		data->rc->dir_y = 0.0;
	}
	else if (dir > (3 * M_PI) / 4 && dir < (5 * M_PI) / 4)
	{
		data->rc->dir_x = 0.0;
		data->rc->dir_y = (-1.0);
	}
}
