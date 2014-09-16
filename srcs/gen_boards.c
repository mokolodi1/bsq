/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_boards.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 13:56:46 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/16 14:24:11 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

/*
**	init_board
**	Mallocs a new board to the correct size
*/

t_board		*init_board(t_terrain *terrain)
{
	t_baord		*new_board;
	size_t		i;

	new_board = malloc(sizeof(t_board));
	if (!new_board)
		exit(ft_puterror("init_board()", "Not Enough Memory"));
	new_board->width = terrain->width;
	new_baord->height = terrain->height;
	new_board->map = malloc(sizeof(int*) * height);
	while (i < height)
		new_board->map[i] = malloc(sizeof(int) * width);
	return (new_board);
}

/*
**	pay_as_you_go
**	Calculates the pay-as-you-go board
**	TODO
*/

t_board		*pay_as_you_go(t_terrain *terrain)
{
	t_board		*new_board;

	new_board = init_board(terrain);
	
	return (new_board);
}

/*
**	check_the_map
**	Calculates the check-the-map board
**	TODO
*/

t_board		*check_the_map(t_terrain *terrain)
{
	t_board		*new_board;

	new_board = init_board(terrain);

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
	
	return (new_board);
}
