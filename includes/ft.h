/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 23:38:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/07 23:38:38 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_H
# define	FT_H

# include	<unistd.h>
# include	<stdlib.h>

void	ft_putchar(char a);
void	ft_putstr(char *str);
size_t	ft_strlen(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_str_is_numeric(char *str);
void	ft_putnbr(int num);
void	ft_swap(int *a, int *b);
int		ft_atoi(char *str);
int		ft_iterative_power(int nb, int power);

#endif
