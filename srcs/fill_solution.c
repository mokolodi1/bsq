/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 20:40:16 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/16 20:45:44 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

/*
**	Fills the solution with the correct characters
*/

void		fill_solution(t_terrain *terrain, t_solution *solution)
{
	int		row;
	int		col;

	row = solution->row;
	while (row < solution->row + solution->size)
	{
		col = solution->col;
		while (col < solution->col + solution->size)
		{
			terrain->map[row][col] = terrain->full;
			col++;
		}
		row++;
	}
}
