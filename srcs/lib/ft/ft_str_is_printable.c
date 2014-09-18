/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 19:13:57 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/03 19:13:58 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		if (*ptr < ' ' && *ptr > '~')
			return (0);
		ptr++;
	}
	return (1);
}