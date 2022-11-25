/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:29:21 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 13:29:22 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){};
	if (argc != 2)
		clean_exit(&data, -1, 2, "Usage: \"./cub3D map_file.cub\"\n");
	init_data(&data);
	init_mlx(&data, data.mlx);
	init_map(&data, argv[1]);
	read_file(&data, argv[1]);
	game_launcher(&data);
	game_loop(&data);
	return (0);
}
