/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:29:35 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 14:30:28 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	clean_exit(t_data *data, int fd_gnl, int fd, char *msg)
{
	char	*line;

	if (fd_gnl >= 0)
	{
		line = get_next_line(fd_gnl);
		while (line)
		{
			if (line)
				free(line);
			line = get_next_line(fd_gnl);
		}
		free(line);
	}
	if (data->mlx)
	{
		mlx_clear_window(data->mlx->id, data->mlx->id_win);
		mlx_destroy_window(data->mlx->id, data->mlx->id_win);
		mlx_destroy_display(data->mlx->id);
	}
	free_all(data);
	ft_putstr_fd(msg, fd);
	exit(fd);
}
