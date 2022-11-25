/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raph <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:34:35 by raph              #+#    #+#             */
/*   Updated: 2021/12/07 16:22:34 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_print_reverse_list(t_list *list)
{
	if (list)
	{
		ft_print_reverse_list(list->next);
		ft_putendl_fd(list->content, 1);
	}
}
