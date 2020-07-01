# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   ft_reader.c                                        :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/02/13 13:15:55 by gyesenia          #+#    #+#             #
#   Updated: 2020/02/13 13:41:06 by gyesenia         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = fdf

HEADER = fdf.h \
         keys_mac.h

SRC =	check_any.c \
		deal_keys.c \
		ft_reader.c \
		utils.c \
		main.c \
		rotation.c \
		switch_proj.c \
		color.c \
		utils_1.c \
		draw.c \
		validator.c

LIB_PATH = ./libft
LIB_OBJ = $(LIB_PATH:.c=.o)
LIB_SRC = $(LIB_PATH:.c)

MINILIBX_PTH = ./minilibx_macos
MINILIBX_SRC = $(MINILIBX_PTH:.c)
MINILIBX_OBJ = $(MINILIBX_PTH:.c=.o)
MINILIBX_M = $(MINILIBX_PTH:.m=.o)

C_FLAGS = -Wall -Wextra -Werror

FDF_FLAGS = -framework OpenGL -framework AppKit

OBJECTS = $(SRC:.c=.o)

.PHONY: all clean fclean re norma runfdf

all:$(NAME)

$(NAME):$(OBJECTS) $(LIB_OBJ) $(LIB_SRC) $(MINILIBX_OBJ) $(MINILIBX_SRC) $(MINILIBX_M)
	@make -C $(LIB_PATH)
	@make -C $(MINILIBX_PTH)
	@gcc $(C_FLAGS) -c $(SRC)
	@gcc -g $(C_FLAGS) $(OBJECTS) -o $(NAME) -L$(LIB_PATH) -lft -L$(MINILIBX_PTH) $(FDF_FLAGS) -lmlx
clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C $(LIB_PATH)
	@make clean -C $(MINILIBX_PTH)

$(OBJECTS): %.o: %.c $(HEADER)
	gcc $(C_FLAGS) -c $< -o $@

fclean:	clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re:	fclean	all

norma:
	/usr/bin/norminette $(SRC) $(HEADER)
runfdf:
	./fdf test_maps/42.fdf
