/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:29:41 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 13:33:46 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
