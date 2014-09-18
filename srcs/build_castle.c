/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_castle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 11:47:07 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 23:21:45 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

int			one_by_one(t_terrain *terrain)
{
	if (terrain->map[0][0] == terrain->obstacle)
	{
		
	}
	return (0);
}

int			width_one(t_terrain *terrain)
{
	(void)terrain;
	return (0);
}

int			height_one(t_terrain *terrain)
{
	(void)terrain;
	return (0);
}

t_solution	*stupid(t_terrain *terr)
{
	t_board		*board;

	board = NULL;
	return (check_the_map(terr, 0, 0, board));
}

int			build_castle(t_terrain *terrain)
{
	t_solution *solution;

	if (terrain->height == 1 && terrain->width == 1)
		return (one_by_one(terrain));
	if (terrain->height == 1)
		return (height_one(terrain));
	if (terrain->width == 1)
		return (width_one(terrain));
	solution = stupid(terrain);
	if (solution->size != 0)
	{
		fill_solution(terrain, solution);
		free(solution);
		return (0);
	}
	else
	{
		free(solution);
		return (1);
	}
}
