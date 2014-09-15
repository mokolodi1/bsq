/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_to_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/13 19:43:46 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/13 19:43:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"ft_file.h"

int		read_all_to_out(char **file_names, int total)
{
	int	i;
	int	fd;

	i = 0;
	while (i < total)
	{
		fd = open(file_names[i], O_RDONLY);
		if (fd == -1)
			return (ft_puterror("open()", file_names[i]));
		if (read_to_out(fd) == -1)
			return (ft_puterror("read()", file_names[i]));
		if (close(fd) == -1)
			return (ft_puterror("close()", file_names[i]));
		i++;
	}
	return (0);
}
