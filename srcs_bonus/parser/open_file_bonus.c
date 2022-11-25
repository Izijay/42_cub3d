/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:29:41 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 14:30:24 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	check_extension(char *pathname)
{
	int	i;

	i = 0;
	while (pathname[i] && pathname[i + 4] != '\0')
		i++;
	if (!ft_strncmp(pathname + i, ".cub", 4))
		return (0);
	return (1);
}

int	open_file(char *pathname)
{
	int	fd;

	if (check_extension(pathname))
		return (-1);
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (fd);
	return (fd);
}
