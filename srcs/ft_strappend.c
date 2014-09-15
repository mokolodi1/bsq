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

char	*ft_strappend(char *dest, char src, char *sep)
{
	int		length;
	char	*str;

	length = ft_strlen(dest) + 1 + ft_strlen(sep);
	str = (char*)malloc(sizeof(char) * (length + 1));
	*str = '\0';
	ft_strcat_sep(str, dest, "");
	ft_strcat_sep(str, sep, "");
	str[length - 1] = src;
	str[length] = '\0';
	return (str);
}
