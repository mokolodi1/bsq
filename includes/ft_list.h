/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 12:44:52 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/10 12:44:53 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LIST_H
# define	FT_LIST_H

# include <stdlib.h>

typedef	struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

t_list			*ft_create_elem(void *data);
t_list			*ft_list_last(t_list *begin_list);
t_list			*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list			*ft_list_push_params(int ac, char **av);
void			ft_list_push_front(t_list **begin_list, void *data);
void			ft_list_push_back(t_list **begin_list, void *data);
void			ft_list_clear(t_list **begin_list);
void			ft_list_reverse(t_list **begin_list);
void			ft_list_foreach(t_list *begin_list, void (*f)(void *));
int				ft_list_size(t_list *begin_list);

#endif