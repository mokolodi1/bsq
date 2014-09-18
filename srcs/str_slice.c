/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_slice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 10:11:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/17 17:04:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

char	*str_slice(char *fish, char knife)
{
	size_t	i;
	size_t	j;
	char	*tail;

	i = 0;
	while (fish[i] != knife && fish[i] != '\0')
		i++;
	//Malloc product string
	tail = malloc((i + 1) * sizeof(char));
	if (!tail)
		exit(ft_puterror("slice()", "Not Enough Memory"));
	//Copy into product string
	j = 0;
	while (j < i)
	{
		tail[j] = fish[j];
		j++;
	}
	tail[i] = '\0';
	j = 0;
	while (fish[i] != '\0')
		fish[j++] = fish[++i];
	if (j == 0)
		fish[0] = '\0';
	return (tail);
}
