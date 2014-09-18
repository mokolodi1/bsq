/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 22:40:54 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 19:01:49 by tfleming         ###   ########.fr       */
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

//	ft_putstr("gen_line start\n");//FIXME
//	ft_putnbr(loc);//FIXME
	
	empty = terr->empty;
	obstacle = terr->obstacle;
	chars = terr->map[line_num];
	none_count = 0;
	while (loc >= 0)
	{
		//ft_putstr("gen_line inside while\n");//FIXME
		if (chars[loc] == empty)
		{
			//ft_putstr("if\n");//FIXME
			none_count++;
		}
		else if (chars[loc] == obstacle)
		{
			//ft_putstr("else if\n");//FIXME
			none_count = 0;
		}
		else
		{
			//ft_putstr("else\n");//FIXME
			return (1);
		}
//		ft_putstr("after\n");//FIXME
		line[loc] = none_count;
		loc--;
//		ft_putstr("end\n");//FIXME
	}
//	ft_putstr("gen_line end\n");//FIXME
	return (0);
}
