/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_catlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 12:47:30 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/14 12:47:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft.h"
#include	"ft_list.h"
#include	"ft_file.h"

char	*str_catlist(t_list *str_list, char *sep, int length)
{
	char	*str;
	int		list_size;

	list_size = ft_list_size(str_list);
	if (list_size == 0)
		return ("\0");
	length += ft_strlen(sep) * (list_size - 1);
	str = (char*)malloc((length + 1) * sizeof(char));
	if (!str)
		return (str);
	*str = '\0';
	while (str_list != 0)
	{
		ft_strcat_sep(str, (char*)str_list->data, sep);
		str_list = str_list->next;
	}
	return (str);
}
