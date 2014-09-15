/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 19:13:57 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/03 19:13:58 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	charcapitalize(char *str_point, int *word_begin)
{
	if (*str_point >= '0' && *str_point <= '9')
	{
		*word_begin = 0;
	}
	else if (*str_point >= 'A' && *str_point <= 'Z')
	{
		if (*word_begin == 0)
			*str_point += 32;
		*word_begin = 0;
	}
	else if (*str_point >= 'a' && *str_point <= 'z')
	{
		if (*word_begin == 1)
			*str_point -= 32;
		*word_begin = 0;
	}
	else
		*word_begin = 1;
	return ;
}

char	*ft_strcapitalize(char *str)
{
	char	*str_point;
	int		word_begin;

	str_point = str;
	word_begin = 1;
	while (*str_point != '\0')
	{
		charcapitalize(str_point, &word_begin);
		str_point++;
	}
	return (str);
}
