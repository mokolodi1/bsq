/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   native_americans.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/18 15:56:23 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/18 15:56:24 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

void	burn_forts(char **map, size_t forts)
{
	size_t	burning;

	burning = 0;
	while (burning < forts)
	{
		if (map[burning])
			free(map[burning]);
		burning++;
	}
}

void	native_americans(t_terrain *free_land)
{
	// ft_putstr("BURN!\n");
	if (free_land == NULL)
		return ;
	// ft_putstr("BURN!!\n");
	if (free_land->map != NULL)
		burn_forts(free_land->map, free_land->height);
	// ft_putstr("BURN!!!\n");
	free(free_land);
	// ft_putstr("BURN!!!!\n");
}
