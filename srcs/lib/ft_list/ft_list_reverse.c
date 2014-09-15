/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 18:20:35 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 18:20:36 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
	t_list	*origin_begin_list;

	if (begin_list == 0 || *begin_list == 0 || (*begin_list)->next == 0)
		return ;
	if ((*begin_list)->next->next == 0)
	{
		(*begin_list)->next->next = *begin_list;
		*begin_list = (*begin_list)->next;
		(*begin_list)->next->next = 0;
		return ;
	}
	origin_begin_list = *begin_list;
	*begin_list = (*begin_list)->next;
	ft_list_reverse(begin_list);
	ft_list_reverse(&origin_begin_list);
}
