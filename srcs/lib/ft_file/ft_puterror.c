/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/13 19:23:55 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/13 19:23:58 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"ft_file.h"

int		ft_puterror(char *err_type, char *err_cause)
{
	while (*err_type != '\0')
	{
		write(2, err_type, 1);
		err_type++;
	}
	write(2, " error: ", 8);
	while (*err_cause != '\0')
	{
		write(2, err_cause, 1);
		err_cause++;
	}
	write(2, "\n", 1);
	return (FT_PUTERROR_RETURN);
}
