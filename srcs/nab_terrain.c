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

t_terrain	*nab_terrain(int fd)
{
	t_terrain	*terranova;
	char		*line;
	char		*spill;
	size_t		line_len;
	size_t		i;

	//Malloc terranova
	terranova = malloc(sizeof(t_terrain));
	if (!terranova)
		exit(ft_puterror("nab_terrain()", "Not Enough Memory (1)"));
	//Initialize line because 'char**'s are stupid
	line = "";
	spill = malloc(sizeof(char) * 1);
	*spill = '\0';
	//Get info line
	line_len = nab_next_line(fd, &line, &spill);
	//Check for bogus: NULL means bogus terrain
	if (line_len < 4)//And if consists of non-negative number and then three printable char: FIXME
		return(NULL);//FIXME
	//Get height
	terranova->height = ft_atoi(line);
	//Malloc map
	terranova->map = malloc(sizeof(char *) * terranova->height);
	if (!terranova->map)
		exit(ft_puterror("nab_terrain()", "Not Enough Memory (2)"));
	//Get other variables
	terranova->empty = (line)[line_len - 3];
	terranova->obstacle = (line)[line_len - 2];
	terranova->full = (line)[line_len - 1];
	line_len = nab_next_line(fd, &line, &spill);
	terranova->width = line_len;
	//Loop through lines "height" times
	i = 0;
	while (i < terranova->height)
	{
		//Check line is correct width
		if (line_len != terranova->width)
			return(NULL);//FIXME
		//Insert line ('malloc'ed already!)
		terranova->map[i] = line;
		//Clear line so terranova can't be modified by accident
		line = "";
		//Get next line
		line_len = nab_next_line(fd, &line, &spill);
		i++;
	}
	//Check for extra text, and thus if terrain is bogus
	if (line_len != 0)
		return(NULL);//FIXME
	return (terranova);
}
