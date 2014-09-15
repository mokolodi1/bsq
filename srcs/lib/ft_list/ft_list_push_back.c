/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 16:41:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 16:41:32 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *curr_cell;

	if (!begin_list)
		return ;
	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	curr_cell = *begin_list;
	while (curr_cell->next != 0)
		curr_cell = curr_cell->next;
	curr_cell->next = ft_create_elem(data);
}
