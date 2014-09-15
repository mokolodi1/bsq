/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 16:35:45 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 16:35:45 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
	t_list *cell;

	cell = malloc(sizeof(t_list));
	if (!cell)
		return (0);
	cell->data = data;
	cell->next = 0;
	return (cell);
}
