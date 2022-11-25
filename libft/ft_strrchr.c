/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:19:40 by ranuytte          #+#    #+#             */
/*   Updated: 2021/12/07 16:21:05 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
