/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 17:24:46 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 17:24:46 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		my_list_push_front(t_list **begin_list, void *data)
{
	t_list *neo_cell;

	neo_cell = ft_create_elem(data);
	if (!neo_cell)
		return (0);
	neo_cell->next = *begin_list;
	*begin_list = neo_cell;
	return (1);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*null_cell;
	t_list	**begin_list;

	null_cell = 0;
	begin_list = &null_cell;
	i = -1;
	while (++i < ac)
	{
		if (my_list_push_front(begin_list, av[i]) == 0)
			return (0);
	}
	return (*begin_list);
}
