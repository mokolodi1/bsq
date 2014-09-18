/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_castle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 11:47:07 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 16:34:09 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

/*
**	Returns 1 if there is a problem with the board (map error)
*/

int			build_castle(t_terrain *terrain)
{
	t_solution *solution;

	solution = check_the_map(terrain);
	// DON'T FORGET TO FREE
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
