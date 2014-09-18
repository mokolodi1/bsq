/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 17:16:13 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/18 19:18:08 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

int		main_stdin(void)
{
	t_terrain	*neosolum;

	neosolum = nab_terrain(0);
	if (neosolum == NULL)
		return (ft_puterror("map error\n", NULL));
	build_castle(neosolum);
	print_terrain(neosolum);
	if (neosolum)
		native_americans(neosolum);
	return (0);
}

int		main(int argc, char **argv)
{
	t_terrain	*neosolum;
	int			i;
	int			fd;

	if (argc == 1)
		return (main_stdin());
	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1 && ft_puterror("map error\n", NULL))
			continue;
		if ((neosolum = nab_terrain(fd)) == NULL)
		{
			ft_putstr("map error\n");
			continue;
		}
		if (close(fd) == -1 && ft_puterror("map error\n", NULL))
			continue;
		build_castle(neosolum);
		print_terrain(neosolum);
		if (neosolum)
			native_americans(neosolum);
	}
	return (0);
}
