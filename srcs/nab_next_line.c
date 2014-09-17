/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nab_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 16:44:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/17 15:26:45 by tfleming         ###   ########.fr       */
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

	ft_putstr("\nNab Next Line: Start\n");//FIXME
	//Store spill for FREE
	spill_temp = *spill;
	//Check spill for leftover text
	ft_putstr("Nab Next Line: SPILL CHECK: Beginning\n");//FIXME
	line_len = 0;
	ft_putstr("SPILL START VALUE:\n");//FIXME
	ft_putstr(*spill);//FIXME
	ft_putstr("\nEND\n");//FIXME
	spill_len = ft_strlen(*spill);
	if ((spill_len > 0) & ((line_len = ft_strlen(*line = str_slice(*spill, '\n'))) < spill_len))
	{
		ft_putstr("Nab Next Line: SPILL CHECK: Spill isn't empty\n");//FIXME
		return (line_len);
	}
	else
	{
		ft_putstr("Nab Next Line: SPILL CHECK: Spill is empty now\n");//FIXME
		// *line = malloc(sizeof(char));
		// if (!*line)
		//	exit(ft_puterror("nab_next_line()", "Not Enough Memory"));
		// **line = '\0';
	}
	ft_putstr("Nab Next Line: SPILL CHECK: End\n");//FIXME

	//Read until a whole line is recovered
	ft_putstr("Nab Next Line: READ LOOP: Start\n");//FIXME
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		//Hold line address for free
		line_temp = *line;
		//Look for line end
		buf[ret] = '\0';
		ft_putstr(buf);//FIXME
		ft_putstr("\n");//FIXME
		line_cut = str_slice(buf, '\n');
		//Add selected text to line
		cut_len = ft_strlen(line_cut);
		ft_strappend(line, line_len, line_cut, cut_len);
		//Free added text and old line
		ft_putstr("Nab Next Line: Line Check: After String Append\n\"");//FIXME
		ft_putstr(*line);//FIXME
		ft_putstr("\"\n");//FIXME
		free(line_cut);
		free(line_temp);
		//Update line length
		line_len += cut_len;
		//Check if an end of line was found
		if (cut_len < (size_t)ret)
		{
			ft_putstr("Nab Next Line: Read Loop BREAK activated\n");//FIXME
			break ;
		}
	}
	ft_putstr("Nab Next Line: READ LOOP: End\n");//FIXME
	if (ret == -1)
		exit(ft_puterror("read()", "line N/A"));
	if (line_len == 0)
		return (line_len);
	//Save spill
	*spill = ft_strdup(buf);
	free(spill_temp);
	ft_putstr("SPILL FINAL VALUE:\n");//FIXME
	ft_putstr(*spill);//FIXME
	ft_putstr("\nEND\n");
	return (line_len);
}
