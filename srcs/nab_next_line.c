/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nab_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 16:44:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/15 16:44:19 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

size_t	nab_next_line(int const fd, char **line, char **overread)
{
	size_t			line_len;
	size_t			ret;
	char			buf[BUF_SIZE + 1];
	size_t			cut_len;
	char			*line_cut;
	//static char	overread[BUF_SIZE + 1];

	*line = "";
	line_len = 0;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		line_cut = str_slice(buf, '\n');
		cut_len = ft_strlen(line_cut);
		ft_strappend(line, line_len, line_cut, cut_len);
		line_len += cut_len;
		if (cut_len < ret)
			break;
	}
	if (ret == -1)
		exit(ft_puterror("read()", "line N/A"));
	*overread = buf;
	return (line_len);
}
