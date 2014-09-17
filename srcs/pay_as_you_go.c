/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pay_as_you_go.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 19:48:53 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/17 12:42:02 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"bsq.h"

/*
**	compare_board
**	Compares for the pay-as-you-go algorithm
**	Returns whether it's a blank square or not
*/

int				compare_board(t_board *board, int row, int col, int size)
{
	int i;

	i = 0;
	while (i < size + 1)
	{
		if (board->map[row + i][col] != board->map[row + i][col + size + 1])
			return (0);
		i++;
	}
	return (1);
}

/*
**	pay_as_you_go
**	Implememts the pay-as-you-go algorithm
**	Returns NULL if no solution found
*/

t_solution		*pay_as_you_go(t_board *board)
{
	size_t	row;
	size_t	col;
	int		big_row;
	int		big_col;
	int		size;

	row = 0;
	size = 0;
	while (row + size < board->height)
	{
		col = 0;
		while (col + size < board->width - 1)
		{
			while (row + size + 1< board->height
							&& col + size < board->width - 2
							&& compare_board(board, row, col, size + 1))
			{
				big_row = row;
				big_col = col;
				size++;
			}
			col++;
		}
		row++;
	}
	if (size)
	{
		ft_putstr("make_solution\n");//FIXME
		return (make_solution(big_row, big_col, size + 1));
	}
	else
		return (NULL);
}
