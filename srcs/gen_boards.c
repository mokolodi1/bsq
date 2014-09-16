/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_boards.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 13:56:46 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/16 19:00:37 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

/*
**	init_board
**	Mallocs a new board to the correct size
**	Will never call from anywhere else: not in .h
*/

t_board		*init_board(t_terrain *terrain)
{
	t_board		*new_board;
	size_t		i;

	new_board = malloc(sizeof(t_board));
	if (!new_board)
		exit(ft_puterror("init_board()", "Not Enough Memory"));
	new_board->width = terrain->width;
	new_board->height = terrain->height;
	new_board->map = malloc(sizeof(int*) * new_board->height);
	i = 0;
	while (i < new_board->height)
	{
		new_board->map[i] = malloc(sizeof(int) * new_board->width);
		i++;
	}
	return (new_board);
}

/*
**	pay_as_you_go
**	Calculates the pay-as-you-go board
*/

t_board		*pay_as_you_go(t_terrain *terrain)
{
	t_board		*new_board;
	size_t		out;
	size_t		in;
	int			curr;

	new_board = init_board(terrain);
	out = 0;
	while (out < terrain->height)
	{
		in = 0;
		curr = 0;
		while (in < terrain->width)
		{
			if (terrain->map[out][in] == terrain->obstacle)
				curr++;
			new_board->map[out][in] = curr;
			in++;
		}
		out++;
	}
		
	return (new_board);
}

/*
**	check_the_map
**	Calculates the check-the-map board
*/

t_board		*check_the_map(t_terrain *terrain)
{
	t_board		*new_board;
	size_t		out;
	size_t		in;
	int			curr;

	new_board = init_board(terrain);
	out = 0;
	while (out < terrain->height - 1)
	{
		in = terrain->width;
		curr = 0;
		while (in > 0)
		{
			if (terrain->map[out][in - 1] == terrain->obstacle)
				curr = 0;
			else
				curr++;
			new_board->map[out][in] = curr;
			in--;
		}
		out++;
	}
	return (new_board);
}

/*
**	check_the_map_up
**	Calculates the second check-the-map board for use in check-the-GPS
**	TODO
*/

t_board		*check_the_map_up(t_terrain *terrain)
{
	t_board		*new_board;

	new_board = init_board(terrain);
	ft_putstr("check_the_map_up: NOT IMPLEMENTED YET\n");
	return (new_board);
}
