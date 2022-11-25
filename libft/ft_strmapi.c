/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:00:26 by ranuytte          #+#    #+#             */
/*   Updated: 2021/12/07 16:21:22 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	void	*ft_memalloc_1(size_t size)
{
	void	*mem;

	mem = malloc(sizeof(*mem) * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

static	char	*ft_strnew_1(size_t size)
{
	char	*str;

	str = ft_memalloc_1(size + 1);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned int		i;

	i = 0;
	str = ft_strnew_1(ft_strlen((char *)s));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
