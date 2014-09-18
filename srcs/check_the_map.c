/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 18:14:38 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/18 16:54:33 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"bsq.h"

/*
**	check_board
**	Compares for the check-the-map algorithm
**	returns if it's good or not (1 = good)
**
**	shift_int_star
**	shifts the int* from the top row to the bottom one
**	returns 1 if there's a problem
**
**	map_error
**	
**
**	make_solution
**	mallocs board, sets it up
**
**	end_stuff
**	free stuff, return stuff, etc
*/

int				check_board(t_board *board, int row, int col, int size)
{
	int i;

	//ft_putstr("check_board: \n");
	//print_board(board, 3, row + size);
	
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
		//ft_putstr("shift int star: cool stuff\n");
		//print_array(board->map[r + size + 1], 3);
		//ft_putstr("r + size + 1 = ");
		//ft_putnbr(r + size + 1);
		//ft_putstr("\nboard->width = ");
		//ft_putnbr(board->width);
		//ft_putstr("\n");
		return (gen_line(terr, board->map[r + size + 1], r + size + 1
						 , board->width - 1));
	}
	// here is where I can do stuff if we already found the largest square
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

t_solution		*check_the_map(t_terrain *terr)
{
	int			row;
	int			col;
	t_board		*board;
	t_solution	*sol;

//	ft_putstr("check_the_map inside\n");//FIXME
	board = make_board(terr);
	sol = make_solution(board);
	row = 0;
	//ft_putstr("check_the_map about to gen first line: board=");//FIXME
	//print_board(board, 3, 1);
	//ft_putstr("\n");
	if (gen_line(terr, board->map[0], 0, board->width - 1))
		return (map_error(board, sol, row));
	else
	{
		//ft_putstr("genned line apparently...\n");//FIXME
		//print_board(board, 4, 1);
		//ft_putstr("end of print_board\n");//FIXME
	}
	//ft_putstr("check_the_map before while loop\n");//FIXME
	//ft_putnbr(sol->size);
	//ft_putchar(' ');
	//ft_putnbr(row);
	while (row + sol->size < board->height)
	{
		col = 0;
		//ft_putstr("check_the_map inside first while\n");//FIXME
		while (col + sol->size < board->width)
		{
			if (check_board(board, row, col, sol->size + 1)
				&& update_solution(sol, row, col, board))
			{
				//ft_putstr("check_the_map inside IF: row=");//FIXME
				//ft_putnbr(row);
				//ft_putstr(", col=");
				//ft_putnbr(col);
				//ft_putstr("\n");
				if (gen_line(terr, board->map[row + sol->size]
							  , row + sol->size, board->width - 1) == 1)
				{
					//ft_putstr("INSIDE SECOND IF\n");
					return (map_error(board, sol, row));
				}
			}
			else
			{
				//ft_putstr("check_the_map inside ELSE: row=");//FIXME
				//ft_putnbr(row);
				//ft_putstr(", col=");
				//	ft_putnbr(col);
				//ft_putstr("\n");
				col++;
			}
		}
		if (shift_int_star(terr, board, row, sol->size))
			return (map_error(board, sol, row));
		row++;
	}
	return (free_board(board, sol));
}
