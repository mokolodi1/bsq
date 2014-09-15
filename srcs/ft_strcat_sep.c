/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 12:07:53 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/14 12:07:54 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strcat_sep(char *dest, char *src, char *sep)
{
	int	i;

	if (*src == '\0')
		return ;
	i = 0;
	while (dest[i] != '\0')
		i++;
	if (i != 0)
	{
		while (*sep != '\0')
		{
			dest[i] = *sep;
			sep++;
			i++;
		}
	}
	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
}
