/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_castle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 11:47:07 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/17 12:42:57 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

void		build_castle(t_terrain *terrain)
{
	ft_putstr("STARTING INTERIOR STUFF\n");//FIXME
	fill_solution(terrain, pay_as_you_go(pay_as_you_go_board(terrain)));
	ft_putstr("ENDING INTERIOR STUFF\n");//FIXME
}
