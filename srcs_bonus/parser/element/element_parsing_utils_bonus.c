/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parsing_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:30:16 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 14:30:27 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	check_extension(char *pathname)
{
	int	i;

	i = 0;
	while (pathname[i] && pathname[i + 4] != '\0')
		i++;
	if (!ft_strncmp(pathname + i, ".xpm", 4))
		return (1);
	return (0);
}

int	check_texture_path(char *path)
{
	int	i;

	if (!path)
		return (1);
	i = 0;
	while (ft_isprint(path[i]))
		i++;
	if (path[i] != '\0')
		ft_memmove(path + i, path + (i + 1), 1);
	if (check_extension(path))
		return (1);
	return (0);
}

int	ft_strstr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] != s2[i])
		return (1);
	return (0);
}

int	spaces_do_not_matter(char **line)
{
	while (**line == ' ')
		(*line)++;
	return (0);
}

void	clean_free_tmp_split(char *tmp, char **split)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	if (split)
	{
		free_split(split);
		split = NULL;
	}
}
