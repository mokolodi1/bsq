/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 22:40:54 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 23:00:13 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"bsq.h"

/*
**	gen_check_map_line
**	generates one line of check-the-map board
**	assumes len(chars) = len(line) and loc = len(chars) - 1
**	returns: if there is a problem (1)
*/

int				gen_line(t_terrain *terr, int *line, int line_num, int loc)
{
	int		none_count;
	char	empty;
	char	obstacle;
	char	*chars;

	empty = terr->empty;
	obstacle = terr->obstacle;
	chars = terr->map[line_num];
	none_count = 0;
	while (loc >= 0)
	{
		if (chars[loc] == empty)
			none_count++;
		else if (chars[loc] == obstacle)
			none_count = 0;
		else
			return (1);
		line[loc] = none_count;
		loc--;
	}
	return (0);
}
