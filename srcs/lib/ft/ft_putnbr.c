/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 16:21:36 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/09 16:21:37 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int num)
{
	if (num < 0)
	{
		ft_putchar('-');
		if (num < -9)
		{
			ft_putnbr((num / 10) * -1);
			ft_putnbr((num % 10) * -1);
		}
		else
			ft_putchar('0' - num);
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar('0' + num);
}
