/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:29:38 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 14:30:24 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	map(t_data *data, int fd)
{
	if (map_parsing(data, fd))
		clean_exit(data, fd, 2, "Error: invalid map\n");
}

static void	element(t_data *data, int fd)
{
	if (element_parsing(data, fd))
		clean_exit(data, fd, 2, "Error: invalid identifier\n");
}

int	read_file(t_data *data, char *path)
{
	int		elem;
	int		fd;

	fd = open_file(path);
	if (fd < 0)
		clean_exit(data, fd, 2, "Error: open failed\n");
	elem = 0;
	while (elem != 6)
	{
		element(data, fd);
		elem++;
	}
	map(data, fd);
	close(fd);
	return (0);
}
