/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:06:13 by ranuytte          #+#    #+#             */
/*   Updated: 2021/12/07 16:15:26 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libft.h"

int	ft_atoi(const char *str)
{
	long	ret;
	long	signe;
	int		i;

	ret = 0;
	signe = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' \
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = 10 * ret + (str[i] - '0');
		i++;
	}
	return (ret * signe);
}
