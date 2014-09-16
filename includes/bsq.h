/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 13:47:22 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/16 18:17:15 by tfleming         ###   ########.fr       */
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
	char	empty;
	char	obstacle;
	char	full;
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

size_t				nab_next_line(int const fd, char **line, char **spill);
char				*str_slice(char *fish, char knife);
void				ft_strappend(char **str, size_t str_len, char *add, size_t add_len);
void				print_terrain(t_terrain *terrain);
void				print_board(t_board *board, int num_width);
t_board				*init_board(t_terrain *terrain);
t_board				*pay_as_you_go(t_terrain *terrain);
t_board				*check_the_map(t_terrain *terrain);

#endif

