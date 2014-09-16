/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_terrain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 16:28:44 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/16 18:48:32 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

/*
**	Prints a terrain
*/

void		print_terrain(t_terrain *terrain)
{
	size_t outer;
	size_t inner;

	outer = 0;
	while (outer < terrain->height)
	{
		inner = 0;
		while (inner < terrain->width)
		{
			ft_putchar(terrain->map[outer][inner]);
			inner++;
		}
		ft_putchar('\n');
		outer++;
	}
}

