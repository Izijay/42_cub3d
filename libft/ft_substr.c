/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:00:24 by ranuytte          #+#    #+#             */
/*   Updated: 2021/12/07 16:20:56 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (len > 0)
	{
		ret[i] = s[start];
		i++;
		start++;
		len--;
	}
	ret[i] = '\0';
	return (ret);
}
