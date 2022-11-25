/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:29:32 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 14:30:28 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_all(t_data *data)
{
	if (data->map)
		free_map(data);
	if (data->mlx)
	{
		free(data->mlx->id);
		free(data->mlx);
	}
	if (data->image_libx)
		free(data->image_libx);
	if (data->rc)
		free(data->rc);
	free_texture(data);
	free_elem(data);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_elem(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->elem[i].id)
			free(data->elem[i].id);
		if (data->elem[i].path)
			free(data->elem[i].path);
		i++;
	}
}

void	free_texture(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->texture[i].txt)
			free(data->texture[i].txt);
	}
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->y_max)
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	free(data->map);
	data->map = NULL;
}
