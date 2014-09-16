/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 12:29:33 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/16 12:30:25 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_list.h"

t_list		*ft_list_pop(t_list **begin_list)
{
	t_list *pop_elem;

	pop_elem = (*begin_list);
	*begin_list = (*begin_list)->next;
	return (pop_elem);
}
