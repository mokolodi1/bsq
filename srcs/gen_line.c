/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 22:40:54 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 15:44:52 by tfleming         ###   ########.fr       */
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

	//ft_putstr("gen_line inside\n");//FIXME
	empty = terr->empty;
	obstacle = terr->obstacle;
	chars = terr->map[line_num];
	none_count = 0;
	//ft_putstr("gen_line before while: loc=");//FIXME
	//ft_putnbr(loc);
	//ft_putchar('\n');
	while (loc >= 0)
	{
		//ft_putstr("gen_line inside while: loc=");//FIXME
		//ft_putnbr(loc);//FIXME
		//ft_putstr(", line_num=");//FIXME
		//ft_putnbr(line_num);//FIXME
		//ft_putchar('\n');
		if (chars[loc] == empty)
			none_count++;
		else if (chars[loc] == obstacle)
			none_count = 0;
		else
			return (1);
		//ft_putstr("about to set line[loc]\n");
		line[loc] = none_count;
		loc--;
	}
	//ft_putstr("gen_line end\n");
	return (0);
}
