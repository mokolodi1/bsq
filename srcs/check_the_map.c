/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 18:14:38 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 23:14:56 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"bsq.h"

void			beginning(t_terrain *terr, t_board **board, t_solution **sol
	, int *row)
{
	*board = make_board(terr);
	*sol = make_solution(*board);
	*row = 0;
}

t_solution		*check_the_map(t_terrain *terr, int row, int col
	, t_board *board)
{
	t_solution	*sol;

	beginning(terr, &board, &sol, &row);
	if (gen_line(terr, board->map[0], 0, board->width - 1))
		return (map_error(board, sol, row));
	while (row + sol->size < board->height)
	{
		col = 0;
		while (col + sol->size < board->width)
		{
			if (check_board(board, row, col, sol->size + 1)
				&& update_solution(sol, row, col, board))
			{
				if (gen_line(terr, board->map[row + sol->size]
								, row + sol->size, board->width - 1) == 1)
					return (map_error(board, sol, row));
			}
			else
				col++;
		}
		if (shift_int_star(terr, board, row, sol->size))
			return (map_error(board, sol, row));
		row++;
	}
	return (free_board(board, sol));
}
