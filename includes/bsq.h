/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 13:47:22 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/16 13:52:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				BSQ_H
# define			BSQ_H

# include			"ft.h"
# include			"ft_file.h"
# include			"ft_list.h"

/*
**	Holds the board we originally catch from input
*/

typedef struct		s_terrain
{
	char	**map;
	size_t	width;
	size_t	height;
}					t_terrain;

/*
**	Holds the boards we make ourselves (numbers are fun)
*/

typedef struct		s_board
{
	int		**map;
	size_t	width;
	size_t	height;
}					t_board;

#endif

