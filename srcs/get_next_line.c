/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 16:44:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/15 16:44:19 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_file.h"

int get_next_line(int const fd, char ** line)
{
	int				ret;
	int				length;
	char			buf[BUF_SIZE + 1];
	static	char	overread[BUF_SIZE + 1];

	length = 0;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_list_push_back(begin_list, ft_strdup(buf));
		length += ret;
	}
	if (ret == -1)
		return (ft_puterror("read()", "N/A"));
	return (length);
}
