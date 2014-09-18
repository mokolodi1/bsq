/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 23:04:47 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 23:40:21 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"bsq.h"

int				check_board(t_board *board, int row, int col, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (board->map[row + i][col] < size)
			return (0);
		i++;
	}
	return (1);
}

int				shift_int_star(t_terrain *terr, t_board *board, int r, int size)
{
	if (r + size + 1 < board->height)
	{
		board->map[r + size + 1] = board->map[r];
		return (gen_line(terr, board->map[r + size + 1], r + size + 1
		, board->width - 1));
	}
	return (0);
}

t_solution		*make_solution(t_board *board)
{
	t_solution	*new_sol;

	new_sol = malloc(sizeof(t_solution));
	if (!new_sol)
		exit(ft_puterror("make_solution()", "Not Enough Memory"));
	new_sol->size = -1;
	update_solution(new_sol, 0, 0, board);
	return (new_sol);
}

t_solution		*map_error(t_board *board, t_solution *sol, int row)
{
	int i;

	i = row;
	while (i <= row + sol->size)
	{
		free(board->map[i]);
		i++;
	}
	free(board->map);
	free(board);
	sol->size = 0;
	return (sol);
}
