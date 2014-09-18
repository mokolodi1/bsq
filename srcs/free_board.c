/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 16:27:36 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 22:57:12 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"bsq.h"

/*
**	Frees the board
*/

t_solution			*free_board(t_board *board, t_solution *sol)
{
	int i;

	if (board == NULL)
		return (sol);
	if (board->map != NULL)
	{
		if (board->height == sol->size)
			i = 0;
		else
			i = board->height - sol->size + 1;
		while (i < board->height)
		{
			if (board->map[i])
				free(board->map[i]);
			i++;
		}
		free(board->map);
	}
	free(board);
	return (sol);
}
