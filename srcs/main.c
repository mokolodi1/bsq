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

#include	<time.h>
#include	<stdio.h>
#include	"bsq.h"

int		main(int argc, char **argv)
{
	t_terrain	*neosolum;
	int	i;
	int	fd;
	clock_t start;
	double nab_terrain_time;
	double build_castle_time;
	double print_terrain_time;

	ft_putstr("Main: Start\n");//FIXME
	nab_terrain_time = 0;
	build_castle_time = 0;
	print_terrain_time = 0;
	start = clock();
	if (argc == 1)
	{
		ft_putstr("Main: Read from STDIN\n");//FIXME
		neosolum = nab_terrain(0);
		nab_terrain_time = ((double)((clock_t)clock() - start)) / CLOCKS_PER_SEC;//FIXME
		if (neosolum == NULL)
			return (ft_puterror("map error\n", NULL));
		//Do important stuff START
		build_castle(neosolum);
		build_castle_time = ((double)((clock_t)clock() - start)) / CLOCKS_PER_SEC;//FIXME
		//Do important stuff END
		ft_putstr("Main: Print STDIN final terrain:\n");//FIXME
		print_terrain(neosolum);
		print_terrain_time = ((double)((clock_t)clock() - start)) / CLOCKS_PER_SEC;//FIXME
		ft_putstr("Main: Free the terrain with scalping...\n");//FIXME
		native_americans(neosolum);
		ft_putstr("Main: Read from STDIN over\n");//FIXME
	}
	i = 0;
	while (++i < argc)
	{
		ft_putstr("Main: Read from ARGV\n");//FIXME
		ft_putstr("File: ");//FIXME
		ft_putstr(argv[i]);//FIXME
		write(1, "\n", 1);//FIXME
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
		ft_putstr("Main: Free the terrain with scalping...\n");//FIXME
		native_americans(neosolum);
	}
	ft_putstr("Main: END\n");//FIXME
	printf("nab_terrain_time:   %f\n", nab_terrain_time);//FIXME
	printf("build_castle_time:  %f\n", build_castle_time - nab_terrain_time);//FIXME
	printf("print_terrain_time: %f\n", print_terrain_time - build_castle_time);//FIXME
	return (0);
}
