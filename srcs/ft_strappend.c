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

#include	"ft_file.h"

void	ft_strappend(char **str, size_t str_len, char *add, size_t add_len)
{
	char	*string;

	string = *str;
	

	length = ft_strlen(dest) + 1 + ft_strlen(sep);
	str = (char*)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (str);
	*str = '\0';
	ft_strcat_sep(str, dest, "");
	ft_strcat_sep(str, sep, "");
	str[length - 1] = src;
	str[length] = '\0';
	return (str);
}
