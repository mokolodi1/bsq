/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 18:44:23 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/01 18:44:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_int_len(char *str)
{
	int length;

	length = 0;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		length++;
		str++;
	}
	return (length);
}

int	pos_power(int a, int b)
{
	int i;

	i = 1;
	while (b > 0)
	{
		i = i * a;
		b--;
	}
	return (i);
}

int ft_atoi(char *str)
{
	int str_int;
	int str_int_sign;
	int str_int_len;
	int i;

	str_int_sign = 1;
	if (str[0] == '-')
	{
		str_int_sign = -1;
		str++;
	}
	str_int_len = ft_str_int_len(str);
	str_int = 0;
	i = 0;
	while (i < str_int_len)
	{
		str_int += (str[i] - 48) * pos_power(10, (str_int_len - 1) - i);
		i++;
	}
	return (str_int * str_int_sign);
}
