/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nab_terrain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 17:59:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/17 16:47:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

void		init_terrain(t_terrain *terranova, char *line, size_t line_len)
{
	terranova->map = malloc(sizeof(char *) * terranova->height);
	if (!terranova->map)
		exit(ft_puterror("nab_terrain()", "Not Enough Memory (2)"));
	terranova->empty = (line)[line_len - 3];
	terranova->obstacle = (line)[line_len - 2];
	terranova->full = (line)[line_len - 1];
}

size_t		nab_terrain_lines(t_terrain *terranova, char *line
							, int fd, char *spill)
{
	size_t	line_len;
	size_t	i;

	line_len = terranova->width;
	i = 0;
	while (i < terranova->height)
	{
		if (line_len != terranova->width)
			return (1);
		terranova->map[i] = line;
		line = "";
		line_len = nab_next_line(fd, &line, &spill);
		ft_putstr(line);
		i++;
	}
	return (line_len);
}

t_terrain	*nab_terrain(int fd)
{
	t_terrain	*terranova;
	char		*line;
	char		*spill;
	size_t		line_len;

	terranova = malloc(sizeof(t_terrain));
	spill = malloc(sizeof(char) * 1);
	if ((!terranova) || (!spill))
		exit(ft_puterror("nab_terrain()", "Not Enough Memory"));
	*spill = '\0';
	line = "";
	line_len = nab_next_line(fd, &line, &spill);
	if (line_len != (size_t)ft_str_int_len(line) + 3
		|| !ft_str_is_printable(line + (line_len - 3))
		|| !(terranova->height = ft_atoi(line)))
		return (NULL);
	init_terrain(terranova, line, line_len);
	line_len = nab_next_line(fd, &line, &spill);
	if (line_len == 0)
		return (NULL);
	terranova->width = line_len;
	line_len = nab_terrain_lines(terranova, line, fd, spill);
	if (line_len != 0)
		return (NULL);
	return (terranova);
}
