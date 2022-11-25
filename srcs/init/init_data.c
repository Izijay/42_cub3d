/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:34:17 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 13:34:18 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_elem(t_data *data)
{
	data->elem[0].id = ft_strdup("NO");
	data->elem[0].path = NULL;
	data->elem[1].id = ft_strdup("SO");
	data->elem[1].path = NULL;
	data->elem[2].id = ft_strdup("WE");
	data->elem[2].path = NULL;
	data->elem[3].id = ft_strdup("EA");
	data->elem[3].path = NULL;
	data->elem[4].id = ft_strdup("F");
	data->elem[4].path = NULL;
	data->elem[5].id = ft_strdup("C");
	data->elem[5].path = NULL;
}

void	init_data(t_data *data)
{
	int	i;

	init_elem(data);
	data->mlx = malloc(sizeof(t_mlx));
	data->image_libx = malloc(sizeof(t_image));
	data->rc = malloc(sizeof(t_raycasting));
	if (!data->mlx || !data->image_libx || !data->rc)
		clean_exit(data, -1, 2, "Error: init data failed\n");
	*(data)->rc = (t_raycasting){};
	data->res_x = 1920;
	data->res_y = 1080;
	i = 0;
	while (i < 4)
	{
		data->texture[i] = (t_txts){};
		i++;
	}
}
