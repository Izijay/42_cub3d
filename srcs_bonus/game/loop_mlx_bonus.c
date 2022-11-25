/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:09:32 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/06 14:30:11 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	exit_game(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(data->mlx->id, data->texture[i].img);
	mlx_destroy_image(data->mlx->id, data->image_libx->img);
	mlx_clear_window(data->mlx->id, data->mlx->id_win);
	mlx_destroy_window(data->mlx->id, data->mlx->id_win);
	mlx_destroy_display(data->mlx->id);
	free_all(data);
	exit(1);
	return (1);
}

static int	key_press(int key, t_data *data)
{
	if (key == ESCAPE)
		exit_game(data);
	if (key == W_KEY)
		data->key_w = 1;
	if (key == A_KEY)
		data->key_a = 1;
	if (key == S_KEY)
		data->key_s = 1;
	if (key == D_KEY)
		data->key_d = 1;
	if (key == LEFT_ARROW)
		data->key_rotate_left = 1;
	if (key == RIGHT_ARROW)
		data->key_rotate_right = 1;
	return (1);
}

static int	key_release(int key, t_data *data)
{
	if (key == ESCAPE)
		exit_game(data);
	if (key == W_KEY)
		data->key_w = 0;
	if (key == A_KEY)
		data->key_a = 0;
	if (key == S_KEY)
		data->key_s = 0;
	if (key == D_KEY)
		data->key_d = 0;
	if (key == LEFT_ARROW)
		data->key_rotate_left = 0;
	if (key == RIGHT_ARROW)
		data->key_rotate_right = 0;
	return (1);
}

static int	game_update(t_data *data)
{
	player_move(data, data->rc);
	raycasting(data, data->rc);
	mlx_put_image_to_window(data->mlx->id, data->mlx->id_win,
		data->image_libx->img, 0, 0);
	return (1);
}

void	game_loop(t_data *data)
{
	mlx_hook(data->mlx->id_win, 17, 1L << 2, &exit_game, data);
	mlx_hook(data->mlx->id_win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->mlx->id_win, 3, 1L << 1, &key_release, data);
	mlx_loop_hook(data->mlx->id, &game_update, data);
	mlx_loop(data->mlx->id);
}
