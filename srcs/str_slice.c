/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_slice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/16 10:11:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/17 15:19:15 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"bsq.h"

char	*str_slice(char *fish, char knife)
{
	size_t	i;
	size_t	j;
	char	*tail;

	ft_putstr("Slice: Start\n");//FIXME
	ft_putstr(fish);//FIXME
	ft_putstr("\n");//FIXME
	//Find slice point
	i = 0;
	while (fish[i] != knife && fish[i] != '\0')
		i++;
	ft_putstr("Tail length: ");//FIXME
	ft_putnbr(i);//FIXME
	ft_putstr("\n");//FIXME
	//Malloc product string
	tail = (char *)malloc((i + 1) * sizeof(char));
	if (!tail)
		exit(ft_puterror("slice()", "Not Enough Memory"));
	//Copy into product string
	ft_putstr("Slice: Write to Tail\n");//FIXME
	tail[i] = '\0';
	j = 0;
	while (j < i)
	{
		tail[j] = fish[j];
		j++;
	}
	tail[i] = '\0';
	//Put remainder 'into' source
	ft_putstr("Slice: Rewrite to Fish\n");//FIXME
	ft_putstr("Tail length: ");//FIXME
	ft_putnbr(j);//FIXME
	ft_putstr("\n");//FIXME
	j = 0;
	while (fish[i] != '\0')
		fish[j++] = fish[++i];
	ft_putstr("Fish old last char: ");//FIXME
	ft_putnbr(i);//FIXME
	ft_putstr("\nValue: ");//FIXME
	ft_putchar(fish[i]);//FIXME
	ft_putstr("\nFish new last char: ");//FIXME
	ft_putnbr(j);//FIXME
	ft_putstr("\nValue: ");//FIXME
	ft_putchar(fish[j - 1]);//FIXME
	ft_putstr("\n");//FIXME
	//fish[j] = '\0';
	//Return product string
	ft_putstr("String Slice: RETURNED\nTail:\n\"");//FIXME
	ft_putstr(tail);//FIXME
	ft_putstr("\"\nRemainder:\n\"");//FIXME
	ft_putstr(fish);//FIXME
	ft_putstr("\"\nString Slice: End\n");//FIXME
	return (tail);
}
