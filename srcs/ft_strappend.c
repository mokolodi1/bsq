/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 11:25:03 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/14 11:25:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

void	ft_strappend(char **str, size_t str_len, char *add, size_t add_len)
{
	char	*output;
	size_t	i;

	output = (char*)malloc(sizeof(char) * (str_len + add_len + 1));
	if (!output)
		exit(ft_puterror("ft_strappend()", "Not Enough Memory"));
	i = 0;
	while ((*str)[i] != '\0')
	{
		output[i] = (*str)[i];
		i++;
	}
	while (*add != '\0')
	{
		output[i++] = *add;
		add++;
	}
	output[i] = '\0';
	*str = output;
}
