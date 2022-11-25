/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:32:42 by ranuytte          #+#    #+#             */
/*   Updated: 2021/12/07 16:22:55 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	int					i;

	i = 0;
	if (len == 0 || s1 == s2)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (len)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		len--;
	}
	return (0);
}
