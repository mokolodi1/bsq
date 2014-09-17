/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nab_terrain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 17:59:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/16 17:59:16 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

t_terrain	*nab_terrain(int fd)
{
	t_terrain	*terranova;
	char		*blank;
	char		*blank_spill;
	char		**line;
	char		**spill;
	size_t		line_len;
	size_t		i;

	//Malloc terranova
	ft_putstr("Nab Terrain: Start\n");//FIXME
	terranova = malloc(sizeof(t_terrain));
	if (!terranova)
		exit(ft_puterror("nab_terrain()", "Not Enough Memory (1)"));
	//Initialize line because 'char**'s are stupid
	ft_putstr("Nab Terrain: Line and Spill Initialization\n");//FIXME
	blank = 0;
	line = &blank;
	blank_spill = "";
	spill = &blank_spill;
	//Get info line
	ft_putstr("Nab Terrain: Grabbing First Line\n");//FIXME
	line_len = nab_next_line(fd, line, spill);
	ft_putstr("Nab Terrain: FIRST LINE\n\"");//FIXME
	ft_putstr(*line);//FIXME
	ft_putstr("\"\nNab Terrain: FIRST LINE LENGTH\n");//FIXME
	ft_putnbr(line_len);
	ft_putstr("\n");//FIXME
	//Check for bogus: NULL means bogus terrain
	ft_putstr("Nab Terrain: First Line Check\n");//FIXME
	if (line_len < 4)//And if consists of non-negative number and then three printable char: FIXME
	{
		ft_putstr("NULL called from 1\n");
		return(NULL);//FIXME
	}
	//Get height
	ft_putstr("Nab Terrain: Grabbing Height\n");//FIXME
	terranova->height = ft_atoi(*line);
	//Malloc map
	ft_putstr("Nab Terrain: Mallocing Map\n");//FIXME
	terranova->map = malloc(sizeof(char *) * terranova->height);
	if (!terranova->map)
		exit(ft_puterror("nab_terrain()", "Not Enough Memory (2)"));
	//Get other variables
	ft_putstr("Nab Terrain: Assigning Map Legend\n");//FIXME
	terranova->empty = (*line)[line_len - 3];
	terranova->obstacle = (*line)[line_len - 2];
	terranova->full = (*line)[line_len - 1];
	//Get first line
	ft_putstr("Nab Terrain: Grabbing Second Line\n");//FIXME
	line_len = nab_next_line(fd, line, spill);
	ft_putstr("Nab Terrain: SECOND LINE\n\"");//FIXME
	ft_putstr(*line);//FIXME
	ft_putstr("\"\nNab Terrain: SECOND LINE LENGTH\n");//FIXME
	ft_putnbr(line_len);
	ft_putstr("\n");//FIXME
	//Get width
	ft_putstr("Nab Terrain: Setting Width\n");//FIXME
	terranova->width = line_len;
	//Loop through lines "height" times
	ft_putstr("Nab Terrain: Line Grabbing Loop: Start\n");//FIXME
	i = 0;
	while (i < terranova->height)
	{
		//Check line is correct width
		if (line_len != terranova->width)
		{
			ft_putstr("NULL called from 2\n");
			return(NULL);//FIXME
		}
		//Insert line ('malloc'ed already!)
		terranova->map[i] = *line;
		//Clear line so terranova can't be modified by accident
		line = &blank;
		//Get next line
		line_len = nab_next_line(fd, line, spill);
		ft_putstr("Nab Terrain: LINE ");//FIXME
		ft_putnbr(i + 2);
		ft_putstr("\n\"");//FIXME
		ft_putstr(*line);//FIXME
		ft_putstr("\"\nNab Terrain: LINE LENGTH\n");//FIXME
		ft_putnbr(line_len);
		ft_putstr("\n");//FIXME
		i++;
	}
	ft_putstr("Nab Terrain: Line Grabbing Loop: End\n");//FIXME
	//Check for extra text, and thus if terrain is bogus
	ft_putstr("Nab Terrain: Check Last Line is Empty\n");//FIXME
	if (line_len != 0)
	{
		ft_putstr("NULL called from 3\n");
		return(NULL);//FIXME
	}
	ft_putstr("Nab Terrain: End\n");//FIXME
	return (terranova);
}

	//nab_next_line(int const fd, char **line, char **spill)

	// typedef struct		s_terrain
	// {
	// 	char	**map;
	// 	size_t	width;
	// 	size_t	height;
	// 	char	empty;
	// 	char	obstacle;
	// 	char	full;
	// }					t_terrain;
