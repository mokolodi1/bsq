/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 17:16:13 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/17 11:56:20 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

int		main(int argc, char **argv)
{
	t_terrain	*neosolum;
	int	i;
	int	fd;

	ft_putstr("Main: Start\n");//FIXME
	if (argc == 1)
	{
		ft_putstr("Main: Read from STDIN\n");//FIXME
		neosolum = nab_terrain(0);
		if (neosolum == NULL)
			exit(ft_puterror("map error\n", NULL));
		//Do important stuff START
		build_castle(neosolum);
		//Do important stuff END
		ft_putstr("Main: Print STDIN final terrain:\n");//FIXME
		print_terrain(neosolum);
		ft_putstr("Main: Read from STDIN over\n");//FIXME
	}
	i = 0;
	while (++i < argc)
	{
		ft_putstr("Main: Read from ARGV\n");//FIXME
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("map error\n");
			continue;
		}
		if ((neosolum = nab_terrain(fd)) == NULL)
		{
			ft_putstr("map error\n");
			continue;
		}
		if (close(fd) == -1)
		{
			ft_putstr("map error\n");
			continue;
		}
		ft_putstr("Main: Read from ARGV loop end\n");//FIXME
		//Do important stuff START
		build_castle(neosolum);	// change
		//Do important stuff END
		ft_putstr("Main: Print ARGV final terrain:\n");//FIXME
		print_terrain(neosolum);
	}
	ft_putstr("Main: END\n");//FIXME
	return (0);
}
