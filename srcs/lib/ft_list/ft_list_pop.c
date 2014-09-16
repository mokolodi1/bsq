/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 12:29:33 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/16 12:30:25 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list		*ft_list_pop(t_list **begin_list)
{
	t_list *old_first;

	old_first = (*begin_list);
	*begin_list = (*begin_list)->next;
	return (old_first);
}
