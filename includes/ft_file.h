/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/13 19:30:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/16 19:07:40 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_FILE_H
# define	FT_FILE_H

# include	<fcntl.h>
# include	"ft.h"
# include	"ft_list.h"

# define	BUF_SIZE			4000
# define	FT_PUTERROR_RETURN	-1

int			ft_puterror(char *err_type, char *err_cause);
int			read_to_out(int fd);
int			read_all_to_out(char **file_names, int total);
int			read_to_list(int fd, t_list **begin_list);
int			strlen_list(t_list *str_list);
void		ft_strcat_sep(char *dest, char *src, char *sep);
char		*str_catlist(t_list *str_list, char *sep, int length);

#endif
