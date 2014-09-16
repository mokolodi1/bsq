# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:54:05 by tgauvrit          #+#    #+#              #
#    Updated: 2014/09/16 18:51:37 by tfleming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			bsq

FT_LIB_NAME =	ft

FT_LIB =		lib$(FT_LIB_NAME).a

LIST_LIB_NAME =	ft_list

LIST_LIB =		lib$(LIST_LIB_NAME).a

FILE_LIB_NAME =	ft_file

FILE_LIB =		lib$(FILE_LIB_NAME).a

CC =			gcc

FLAGS =			-Wall -Werror -Wextra

HEADER_DIR =	./includes/

EX_SRC_DIR =	./srcs/

EX_COMPILED =	main.o \
				str_catlist.o \
				strlen_list.o \
				ft_strcat_sep.o \
				ft_strappend.o \
				str_slice.o \
				nab_next_line.o \
				gen_boards.o \
				print_terrain.o \
				print_board.o

FILE_SRC_DIR =	./srcs/lib/ft_file/

FILE_COMPILED =	ft_puterror.o \
				read_to_out.o \
				read_all_to_out.o \
				read_to_list.o

LIST_SRC_DIR =	./srcs/lib/ft_list/

LIST_COMPILED =	ft_create_elem.o \
				ft_list_at.o \
				ft_list_clear.o \
				ft_list_foreach.o \
				ft_list_last.o \
				ft_list_push_back.o \
				ft_list_push_front.o \
				ft_list_push_params.o \
				ft_list_reverse.o \
				ft_list_size.o \
				ft_list_pop.o

FT_SRC_DIR =	./srcs/lib/ft/

FT_COMPILED =	ft_atoi.o \
				ft_iterative_power.o \
				ft_putstr.o \
				ft_putchar.o \
				ft_putnbr.o \
				ft_strcapitalize.o \
				ft_strcmp.o \
				ft_strcpy.o \
				ft_strdup.o \
				ft_strlen.o \
				ft_strlowcase.o \
				ft_strupcase.o \
				ft_str_is_numeric.o \
				ft_swap.o

COMPILED =		$(FT_COMPILED) \
				$(LIST_COMPILED) \
				$(FILE_COMPILED) \
				$(EX_COMPILED)

all: $(NAME)

$(NAME): $(FT_LIB) $(LIST_LIB) $(FILE_LIB) $(EX_COMPILED)
	$(CC) -o $(NAME) -L. -l$(FT_LIB_NAME) -l$(LIST_LIB_NAME) -l$(FILE_LIB_NAME) $(FLAGS) -I $(HEADER_DIR) $(EX_COMPILED)

$(EX_COMPILED): %.o: $(EX_SRC_DIR)%.c
	$(CC) -c $(FLAGS) -I $(HEADER_DIR) $< -o $@

$(FILE_LIB): $(FILE_COMPILED)
	ar rc $(FILE_LIB) $(FILE_COMPILED)

$(FILE_COMPILED): %.o: $(FILE_SRC_DIR)%.c
	$(CC) -c $(FLAGS) -L. -l$(FT_LIB_NAME) -l$(LIST_LIB_NAME) -I $(HEADER_DIR) $< -o $@

$(LIST_LIB): $(LIST_COMPILED)
	ar rc $(LIST_LIB) $(LIST_COMPILED)

$(LIST_COMPILED): %.o: $(LIST_SRC_DIR)%.c
	$(CC) -c $(FLAGS) -L. -l$(FT_LIB_NAME) -I $(HEADER_DIR) $< -o $@

$(FT_LIB): $(FT_COMPILED)
	ar rc $(FT_LIB) $(FT_COMPILED)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)%.c
	$(CC) -c $(FLAGS) -I $(HEADER_DIR) $< -o $@

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(NAME) $(FT_LIB) $(LIST_LIB)

re: fclean all
