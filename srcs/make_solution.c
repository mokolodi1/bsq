/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 20:19:40 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/17 00:01:29 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

/*
**	Makes a t_solution
*/

t_solution	*make_solution(int row, int col, int size)
{
	t_solution *solution;

	solution = malloc(sizeof(t_solution));
	solution->row = row;
	solution->col = col;
	solution->size = size;
	return solution;
}
