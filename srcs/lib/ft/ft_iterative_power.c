/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 13:46:57 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/02 13:46:58 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_power(int nb, int power)
{
	int i;

	if (power < 0)
		return (0);
	i = 1;
	while (power > 0)
	{
		i = i * nb;
		power--;
	}
	return (i);
}
