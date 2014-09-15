/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 12:33:01 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/14 12:33:02 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"ft_file.h"

int	read_to_list(int fd, t_list **begin_list)
{
	int		ret;
	int		length;
	char	buf[BUF_SIZE + 1];

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
