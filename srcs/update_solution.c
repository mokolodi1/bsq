/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 19:06:11 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 15:44:34 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

/*
**	makes size bigger; changes row, col
**	mallocs a new int* for check_the_map
**	returns: 1 if no problem making new thing
*/

int			update_solution(t_solution *sol, int row, int col
							, t_board *board)
{
	//ft_putstr("update solution\n");
	sol->size++;
	sol->row = row;
	sol->col = col;
	if (row + sol->size  < board->height
				&& col + sol->size < board->width)
	{
		//ft_putstr("row + sol->size: ");
		//ft_putnbr(row + sol->size);
		//ft_putchar('\n');
		board->map[row + sol->size] = malloc(sizeof(int) * board->width);
		if (!board->map[row + sol->size])
			exit(ft_puterror("update_sollution()", "Not Enough Memory"));
		return (1);
	}
	else
		return (0);
}
