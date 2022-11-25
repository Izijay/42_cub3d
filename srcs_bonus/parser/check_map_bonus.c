/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:30:09 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 14:30:20 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	hunting_the_zero(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

static int	check_space(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->y_max)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ' ')
				if (check_around_space(data, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->y_max)
	{
		if ((i == 0 || i == (data->y_max - 1)) && \
				hunting_the_zero(data->map[i]))
			return (1);
		j = 0;
		while (ft_isprint(data->map[i][j]))
			j++;
		if (data->map[i][j - 1] != '1')
			return (1);
		if (check_empty_spaces(data, i, j))
			return (1);
		i++;
	}
	return (0);
}

static int	check_first_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		return (1);
	return (0);
}

int	check_map(t_data *data)
{
	int	i;

	if (get_player_pos(data))
		return (1);
	i = 0;
	while (i < data->y_max)
	{
		if (check_first_char(data->map[i]))
			return (1);
		if (check_border(data))
			return (1);
		if (check_space(data))
			return (1);
		i++;
	}
	return (0);
}
