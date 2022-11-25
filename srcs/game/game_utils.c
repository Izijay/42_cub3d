/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:33:32 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/03 14:10:32 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_path(t_data *data)
{
	data->texture[NO_WALL].path = data->elem[0].path;
	data->texture[SO_WALL].path = data->elem[1].path;
	data->texture[WE_WALL].path = data->elem[2].path;
	data->texture[EA_WALL].path = data->elem[3].path;
}

int	modif_mlx_new_img(void *mlx_ptr, t_image *image_libx, int res_x, int res_y)
{
	image_libx->img = mlx_new_image(mlx_ptr, res_x, res_y);
	if (!image_libx->img)
		return (0);
	image_libx->addr = mlx_get_data_addr(image_libx->img, &image_libx->bpp,
			&image_libx->size_line, &image_libx->endian);
	return (1);
}

void	modif_mlx_pixel_put(t_image *image_libx, int x, int y, int color)
{
	char	*dst;

	dst = image_libx->addr + (y * image_libx->size_line + x
			* (image_libx->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	init_txts_struct(t_data *data)
{
	fill_path(data);
	if (!modif_mlx_new_img(data->mlx->id, data->image_libx,
			data->res_x, data->res_y))
		return (0);
	if (!loading_texts(data, &data->texture[NO_WALL])
		|| !loading_texts(data, &(data)->texture[SO_WALL])
		|| !loading_texts(data, &(data)->texture[WE_WALL])
		|| !loading_texts(data, &(data)->texture[EA_WALL]))
		return (0);
	return (1);
}

int	game_launcher(t_data *data)
{
	if (!init_txts_struct(data))
		clean_exit(data, -1, 2, "Error: Textures loading failed\n");
	init_plan(data);
	init_ray_dir(data);
	return (1);
}
