/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 17:38:56 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/14 17:38:57 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_file.h"

int	strlen_list(t_list *str_list)
{
	int str_len;

	str_len = 0;
	while (str_list != 0)
	{
		str_len += ft_strlen(str_list->data);
		str_list = str_list->next;
	}
	return (str_len);
}
