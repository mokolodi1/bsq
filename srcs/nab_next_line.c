/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nab_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 16:44:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/17 16:41:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

size_t	slice_and_stick(char **line, size_t *line_len_ptr, char *line_cut)
{
	char			*line_temp;
	size_t			line_len;
	size_t			cut_len;

	line_temp = *line;
	line_len = *line_len_ptr;
	cut_len = ft_strlen(line_cut);
	ft_strappend(line, line_len, line_cut, cut_len);
	free(line_cut);
	free(line_temp);
	line_len += cut_len;
	*line_len_ptr = line_len;
	return (cut_len);
}

size_t	nab_next_line(int const fd, char **line, char **spill)
{
	int				ret;
	char			buf[BUF_SIZE + 1];
	size_t			spill_len;
	size_t			line_len;
	char			*spill_temp;

	spill_temp = *spill;
	spill_len = ft_strlen(*spill);
	if ((spill_len > 0) & ((line_len =
		ft_strlen(*line = str_slice(*spill, '\n'))) < spill_len))
		return (line_len);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((ret == 0) || (buf[ret - 1] == '\0' && buf[ret - 2] != '\n'))
			return (0);
		if (slice_and_stick(line, &line_len, str_slice(buf, '\n'))
			< (size_t)ret)
			break ;
	}
	if (ret == -1)
		exit(ft_puterror("read()", "line N/A"));
	*spill = ft_strdup(buf);
	free(spill_temp);
	return (line_len);
}
