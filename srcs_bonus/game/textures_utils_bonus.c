/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:13:29 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/06 14:30:17 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	trgb_convertor(int t, int r, int g, int b)
{
	int		color;

	color = t << 24;
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}

int	which_texture(int side)
{
	if (side == 0)
		return (SO_WALL);
	else if (side == 1)
		return (EA_WALL);
	else if (side == 2)
		return (NO_WALL);
	return (WE_WALL);
}
