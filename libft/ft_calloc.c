/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:01:38 by ranuytte          #+#    #+#             */
/*   Updated: 2021/12/07 16:16:02 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	ret = malloc(size * count);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, size * count);
	return ((void *)ret);
}
