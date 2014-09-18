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
	size_t	outer;
	size_t	height;
	size_t	width;

	height = terrain->height;
	width = terrain->width;
	outer = 0;
	while (outer < height)
	{
		write(1, terrain->map[outer], width);
		write(1, "\n", 1);
		outer++;
	}
}
