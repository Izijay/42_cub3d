/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around_space_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:30:12 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 14:30:19 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	check_line(t_data *data, int pos_i, int pos_j)
{
	int	cpy_j;

	cpy_j = pos_j;
	while (pos_j > 0 && data->map[pos_i][pos_j] == ' ')
		pos_j--;
	if (data->map[pos_i][pos_j] == '1' || pos_j == 0)
		return (0);
	if (data->map[pos_i][pos_j] != '1')
		return (1);
	else
	{
		while (cpy_j < data->y_max && data->map[cpy_j][pos_j] == ' ')
			cpy_j++;
		if (data->map[pos_j][cpy_j] == '1' || \
				cpy_j == (int)ft_strlen(data->map[pos_i]))
			return (0);
		else
			return (1);
	}
}

static int	check_v_line_up(t_data *data, int pos_i, int pos_j)
{
	while (pos_i > 0 && data->map[pos_i][pos_j] == ' ')
		pos_i--;
	if (data->map[pos_i][pos_j] == '1' || pos_i == 0)
		return (0);
	if (data->map[pos_i][pos_j] != '1')
		return (1);
	return (0);
}

static int	check_v_line_down(t_data *data, int pos_i, int pos_j)
{
	while (pos_i < (data->y_max - 1) && data->map[pos_i][pos_j] == ' ')
		pos_i++;
	if (data->map[pos_i][pos_j] == '1' || pos_i == data->y_max - 1)
		return (0);
	else
		return (1);
	return (0);
}

int	check_around_space(t_data *data, int pos_i, int pos_j)
{
	if (check_line(data, pos_i, pos_j))
		return (1);
	if (check_v_line_up(data, pos_i, pos_j) || \
		check_v_line_down(data, pos_i, pos_j))
		return (1);
	return (0);
}
