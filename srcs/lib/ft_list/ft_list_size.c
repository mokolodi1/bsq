/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 17:06:41 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 17:07:09 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int	i;

	if (!begin_list)
		return (0);
	i = 1;
	while (begin_list->next != 0)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
