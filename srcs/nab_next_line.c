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

size_t	nab_next_line(int const fd, char **line, char **spill)
{
	int				ret;
	char			buf[BUF_SIZE + 1];
	size_t			spill_len;
	size_t			line_len;
	size_t			cut_len;
	char			*line_cut;
	char			*line_temp;
	char			*spill_temp;

	//Store spill for FREE
	spill_temp = *spill;
	//Check spill for leftover text
	line_len = 0;
	spill_len = ft_strlen(*spill);
	if ((spill_len > 0) & ((line_len = ft_strlen(*line = str_slice(*spill, '\n'))) < spill_len))
		return (line_len);

	//Read until a whole line is recovered
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		//Hold line address for free
		line_temp = *line;
		//Look for line end
		buf[ret] = '\0';
		line_cut = str_slice(buf, '\n');
		//Add selected text to line
		cut_len = ft_strlen(line_cut);
		ft_strappend(line, line_len, line_cut, cut_len);
		//Free added text and old line
		free(line_cut);
		free(line_temp);
		//Update line length
		line_len += cut_len;
		//Check if an end of line was found
		if (cut_len < (size_t)ret)
			break ;
	}
	if (ret == -1)
		exit(ft_puterror("read()", "line N/A"));
	if (line_len == 0)
		return (line_len);
	//Save spill
	*spill = ft_strdup(buf);
	free(spill_temp);
	return (line_len);
}
