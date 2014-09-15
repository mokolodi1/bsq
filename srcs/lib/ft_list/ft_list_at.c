/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 18:03:23 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 18:03:24 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (nbr-- > 0)
		if (begin_list != 0)
			begin_list = begin_list->next;
	return (begin_list);
}
