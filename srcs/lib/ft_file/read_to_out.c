/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/13 19:20:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/13 19:20:20 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"ft_file.h"

int		read_to_out(int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	if (ret == -1)
		ft_puterror("read()", "STDIN");
	return (0);
}
