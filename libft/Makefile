# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 12:53:10 by gyesenia          #+#    #+#              #
#    Updated: 2020/02/08 23:21:56 by gyesenia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRC = ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_memcmp.c \
	  ft_strlen.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	  ft_strrchr.c ft_strstr.c ft_strdup.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
	  ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	  ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_cut_word.c ft_count_words.c ft_swap.c ft_itoa_is_negative.c \
	  ft_list_size.c ft_atoi_base.c

C_FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

all: $(SRC) $(NAME)

$(NAME): $(OBJECTS)
	@@ar rc $(NAME) $(OBJECTS)
	@@ranlib $(NAME)
	@echo the library is assembled
%.o: %.c
	@@gcc $(C_FLAGS) -c -o $@ $<
clean:
	@@/bin/rm -f $(OBJECTS)
	@echo objects files deleted
fclean: clean
	@@/bin/rm -f $(NAME)
	@echo libft.a deleted

re: fclean all
