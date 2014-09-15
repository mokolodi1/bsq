/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 19:23:47 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 19:23:48 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != 0)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
