/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/04 20:35:15 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/04 20:35:15 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft.h"

char		*ft_strdup(char *src)
{
	char			*dup;
	int				i;
	int				length;

	length = ft_strlen(src);
	dup = (char *)malloc((length + 1) * sizeof(char));
	if (!dup)
		return (dup);
	i = 0;
	while (i < length)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
