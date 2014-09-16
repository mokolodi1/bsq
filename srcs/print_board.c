/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 15:40:39 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/16 16:08:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

int			num_of_digits(int num)
{
	if (num <= 9)
		return (1);
	return (1 + num_of_digits(num / 10));
}

void		ft_putchars(char c, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		ft_putchar(c);
		i++;
	}
}

/*
**	Prints a board
*/

void		print_board(t_board *board, int num_width)
{
	size_t outer;
	size_t inner;

	outer = 0;
	while (outer < board->height)
	{
		inner = 0;
		while (inner < board->width)
		{
			ft_putchars(' ', num_width
						- num_of_digits(board->map[outer][inner]));
			ft_putnbr(board->map[outer][inner]);
		}
	}
}
