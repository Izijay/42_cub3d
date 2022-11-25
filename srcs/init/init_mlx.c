/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:34:08 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 13:34:09 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_data *data, t_mlx *mlx)
{
	mlx->id = mlx_init();
	if (!mlx->id)
		clean_exit(data, -1, 2, "Error: mlx_init failed\n");
	mlx->id_win = mlx_new_window(mlx->id, data->res_x, data->res_y, "Cub3D");
	if (!mlx->id_win)
		clean_exit(data, -1, 2, "Error: mlx_new_window failed\n");
}
