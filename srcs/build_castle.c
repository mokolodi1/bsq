/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_castle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 11:47:07 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 20:46:13 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

/*
**	build_castle
**	Returns 1 if there is a problem with the board (map error)
**	Screw maps with one-size dimensions...
*/

/*int			one_by_one(t_terrain *terrain)
{
	char	prick;

	prick = terrain->map[0][0];
	if (prick == terrain->obstacle)
		return (1);
	if (prick == terrain->empty)
	{
		terrain->map[0][0] = terrain->full;
		return (0);
	}
	else
		return (1);
}

int			height_one(t_terrain *terrain)
{
	(void)terrain;
	ft_putstr("HEIGHT = 1!\n");
	return (0);
}

int			width_one(t_terrain *terrain)
{
	(void)terrain;
	ft_putstr("WIDTH = 1!\n");
	return (0);
}*/

int			build_castle(t_terrain *terrain)
{
	t_solution *solution;

	/*if (terrain->height == 1 && terrain->width == 1)
		return (one_by_one(terrain));
	if (terrain->height == 1)
		return (height_one(terrain));
	if (terrain->width == 1)
	return (width_one(terrain));*/
	solution = check_the_map(terrain);
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
