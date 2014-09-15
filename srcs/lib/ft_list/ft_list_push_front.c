/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 16:53:36 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 16:53:37 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *neo_cell;

	if (!begin_list)
	{
		neo_cell = 0;
		begin_list = &neo_cell;
	}
	neo_cell = ft_create_elem(data);
	if (!neo_cell)
		return ;
	neo_cell->next = *begin_list;
	*begin_list = neo_cell;
}
