/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 16:27:36 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 16:51:29 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"bsq.h"

/*
**	Frees the board
*/

t_solution			*free_board(t_board *board, t_solution *sol)
{
	int i;

	i = board->height - sol->size - 1;
	while (i < board->height)
	{
		free(board->map[i]);
		i++;
	}
	free(board->map);
	free(board);
	return (sol);
}
