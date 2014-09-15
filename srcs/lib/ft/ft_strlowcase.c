/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 19:13:57 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/03 19:13:58 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*str_point;

	str_point = str;
	while (*str_point != '\0')
	{
		if (*str_point >= 'A' && *str_point <= 'Z')
			*str_point += 32;
		str_point++;
	}
	return (str);
}
