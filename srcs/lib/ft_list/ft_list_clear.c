/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 17:49:59 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 17:50:00 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_clear(t_list **begin_list)
{
	if (begin_list == 0 || *begin_list == 0)
		return ;
	if ((*begin_list)->next != 0)
		ft_list_clear(&((*begin_list)->next));
	free(*begin_list);
	*begin_list = 0;
}
