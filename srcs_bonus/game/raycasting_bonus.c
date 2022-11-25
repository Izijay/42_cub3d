/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:38:26 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/06 14:30:14 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_raycasting(t_data *data, int x)
{
	data->rc->camera_x = 2.0 * (double)(data->res_x - 1 - x)
		/ (double)data->res_x - 1;
	data->rc->ray_dir_x = data->rc->dir_x + data->rc->plane_x
		* data->rc->camera_x;
	data->rc->ray_dir_y = data->rc->dir_y + data->rc->plane_y
		* data->rc->camera_x;
	data->rc->map_x = (int)data->rc->pos_x;
	data->rc->map_y = (int)data->rc->pos_y;
	data->rc->delta_dist_x = fabs(1 / data->rc->ray_dir_x);
	data->rc->delta_dist_y = fabs(1 / data->rc->ray_dir_y);
}

/**
 * It calculates the distance
 * from the player to the next wall in the x and y directions
 */
void	side_dist(t_raycasting *rc, t_data *data)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (data->player_pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - data->player_pos_x)
			* rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (data->player_pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - data->player_pos_y)
			* rc->delta_dist_y;
	}
}

/**
 * It calculates the distance
 * from the player to the wall, and then uses that distance to calculate the
 * height of the wall
 */
void	wall_dist(t_data *data)
{
	if (data->rc->side == 0)
		data->rc->perp_wall_dist = (data->rc->map_x - data->player_pos_x
				+ (1 - data->rc->step_x) / 2) / data->rc->ray_dir_x;
	else
		data->rc->perp_wall_dist = (data->rc->map_y - data->player_pos_y
				+ (1 - data->rc->step_y) / 2) / data->rc->ray_dir_y;
	data->rc->line_height = (int)data->res_y / data->rc->perp_wall_dist;
	data->rc->draw_start = (int)(-data->rc->line_height) / 2 + data->res_y / 2;
	if (data->rc->draw_start < 0)
		data->rc->draw_start = 0;
	data->rc->draw_end = data->rc->line_height / 2 + data->res_y / 2;
	if (data->rc->draw_end >= data->res_y)
		data->rc->draw_end = data->res_y;
}

/**
 * It calculates the distance from the player to the next wall in the x and y
 * directions, and then moves the player to the next wall
 */
static void	algo_dda(t_data *data, t_raycasting *rc)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (data->map[(int)rc->map_y][(int)rc->map_x] == '1')
			hit = 1;
	}
}

int	raycasting(t_data *data, t_raycasting *rc)
{
	int	x;

	x = -1;
	rc->pos_y = data->player_pos_y;
	rc->pos_x = data->player_pos_x;
	while (++x < data->res_x)
	{
		init_raycasting(data, x);
		side_dist(rc, data);
		algo_dda(data, rc);
		wall_dist(data);
		print_txts(x, data, rc);
	}
	return (1);
}
