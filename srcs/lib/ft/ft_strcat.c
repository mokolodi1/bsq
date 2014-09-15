/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 22:16:02 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/02 22:16:03 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	char	*end_dest;

	i = 0;
	while (dest[i] != '\0')
		i++;
	end_dest = dest + i;
	i = 0;
	while (src[i] != '\0')
	{
		end_dest[i] = src[i];
		i++;
	}
	end_dest[i] = '\0';
	return (dest);
}
