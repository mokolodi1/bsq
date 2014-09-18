/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 22:34:19 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 15:28:54 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"bsq.h"

/*
**	allocates memory for the board (only the int*), sets it up
**	also mallocs first line of the board
*/

t_board			*make_board(t_terrain *terrain)
{
	t_board		*new_board;

	new_board = malloc(sizeof(t_board));
	if (!new_board)
		exit(ft_puterror("make_board()", "Not Enough Memory"));
	new_board->width = terrain->width;
	new_board->height = terrain->height;
	new_board->map = malloc(sizeof(int*) * new_board->height);
	if (!new_board->map)
		exit(ft_puterror("make_board()", "Not Enough Memory"));
	return (new_board);
}
