/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:07:42 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/06 10:54:33 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_plan(t_raycasting *rc)
{
	int	side;

	side = 0;
	if (rc->side == 0)
	{
		if (rc->step_x < 0)
			side = 3;
		else
			side = 1;
	}
	else
	{
		if (rc->step_y < 0)
			side = 0;
		else
			side = 2;
	}
	return (side);
}

int	loading_texts(t_data *data, t_txts *texture)
{
	int	i;
	int	stop_load;

	texture->img = mlx_xpm_file_to_image(data->mlx->id, texture->path,
			&texture->width, &texture->height);
	if (!texture->img)
		return (0);
	texture->addr = (unsigned int *)mlx_get_data_addr(texture->img,
			&texture->bpp, &texture->size_line, &texture->endian);
	texture->txt = ft_calloc(texture->width * texture->height,
			sizeof(unsigned int));
	if (!texture->txt)
		return (0);
	i = -1;
	stop_load = texture->width * texture->height;
	while (++i < stop_load)
		texture->txt[i] = texture->addr[i];
	return (1);
}

/*
 * It calculates the x coordinate of the texture to be used
 */
int	algo_txts_x(t_raycasting *rc, t_txts *txt, int side)
{
	int		txt_x;
	double	wall_x;

	txt_x = 0;
	wall_x = 0;
	if (rc->side == 0)
		wall_x = rc->pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		wall_x = rc->pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	txt_x = (int)(wall_x * (double)txt->width);
	if (side == 0)
		txt_x = txt->width - txt_x - 1;
	if (side == 3)
		txt_x = txt->width - txt_x - 1;
	return (txt_x);
}

static int	print_txts_helper(t_data *data, t_txts *txt, int y, int x)
{
	double	txt_y;
	int		color;

	txt_y = 0.0;
	color = 0;
	while (y >= data->rc->draw_start && y < data->rc->draw_end)
	{
		txt_y = (int)(((y - data->res_y / 2 + data->rc->line_height / 2)
					* txt->height) / data->rc->line_height);
		color = txt->txt[txt->width * (int)floor(txt_y) + txt->txts_x];
		modif_mlx_pixel_put(data->image_libx, x, y, color);
		++y;
	}
	return (y);
}

void	print_txts(int x, t_data *data, t_raycasting *rc)
{
	int		y;
	int		side;
	int		rgb[2];
	int		txt_wall;

	y = 0;
	side = ft_plan(rc);
	txt_wall = which_texture(side);
	data->texture[txt_wall].txts_x = algo_txts_x(rc,
			&data->texture[txt_wall], side);
	rgb[0] = trgb_convertor(0, data->elem[5].rgb[0],
			data->elem[5].rgb[1], data->elem[5].rgb[2]);
	rgb[1] = trgb_convertor(0, data->elem[4].rgb[0],
			data->elem[4].rgb[1], data->elem[4].rgb[2]);
	while (y < rc->draw_start)
		modif_mlx_pixel_put(data->image_libx, x, y++, rgb[0]);
	y = print_txts_helper(data, &data->texture[txt_wall], y, x);
	while (rc->draw_end <= y && y < data->res_y)
		modif_mlx_pixel_put(data->image_libx, x, y++, rgb[1]);
}
