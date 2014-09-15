/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 17:16:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 17:16:13 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	while (begin_list->next != 0)
		begin_list = begin_list->next;
	return (begin_list);
}
