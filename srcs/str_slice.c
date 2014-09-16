/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_slice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 10:11:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/16 10:11:13 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

char	*str_slice(char *fish, char knife)
{
	size_t	i;
	size_t	j;
	char	*tail;

	//Find slice point
	i = 0;
	while (fish[i] != knife && fish[i] != '\0')
		i++;
	//Malloc product string
	tail = (char *)malloc((i + 1) * sizeof(char));
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
	//Put remainder 'into' source
	j = 0;
	while (fish[i] != '\0')
		fish[j++] = fish[++i];
	//Return product string
	return (tail);
}
