# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 13:40:46 by marvin            #+#    #+#              #
#    Updated: 2024/11/09 13:40:46 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


########################
#        Color         #
########################

RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
PURPLE = \033[1;35m
RESET  = \033[0m

########################
#      MiniLibX        #
########################

MLX_DIR := lib/minilibx
MLX := $(MLX_DIR)/libmlx.so


########################
#       Params         #
########################

NAME = so_long

CC = cc
CFLAGS := -Wall -Wextra -Werror -g -Ilib/minilibx
AR = ar rcs

########################
#        Files         #
########################

PRINTF_FILES = lib/ft_printf/ft_pointer.c\
				lib/ft_printf/ft_put.c\
				lib/ft_printf/ft_printf_handle.c\
				lib/ft_printf/ft_printf.c\

GNL_FILES = lib/gnl/get_next_line.c \
        	lib/gnl/get_next_line_utils.c \

LIBFT_FILES = lib/ft_itoa.c\

SRC = ft_build_map.c\
	ft_check_map.c\
	ft_flood_fill.c\
	ft_check_len_3.c\
	ft_move_player.c\
	ft_display.c\
	ft_clean.c\
	main.c\

BONUS = ft_print_bonus.c\

########################
#       Object         #
########################

OBJ = $(SRC:.c=.o) $(BONUS:.c=.o)
OBJ_LIB = $(GNL_FILES:.c=.o) $(PRINTF_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

########################
#     Assignment       #
########################

$(NAME): $(OBJ) $(OBJ_LIB)
	@if [ ! -f lib/minilibx/libmlx.a ];\
	then $(MLX);\
	fi
	
	@$(CC) $(OBJ) $(OBJ_LIB) -L$(MLX_DIR) -lmlx -lm -lX11 -lXext -o $(NAME)
	@echo "$(PURPLE)";
	@echo "  44444    44444       2222      22222   22   22    2222";
	@echo " 44   44  44   44       22      22   22  222  22   22  22";
	@echo " 4        44   44       22      22   22  2222 22  22";
	@echo "  44444   44   44       22      22   22  22 2222  22";
	@echo "      44  44   44       22   2  22   22  22  222  22  222";
	@echo " 44   44  44   44       22  22  22   22  22   22   22  22";
	@echo "  44444    44444       2222222   22222   22   22    22222";
	@echo "$(RESET)";

$(MLX):
	@make --no-print-directory -C $(MLX_DIR) -s -j all

########################
#      Control         #
########################

all: $(NAME)
	gcc generateur_map/map_generator.c
	./a.out

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(MLX) $(OBJ_LIB)
	@echo "$(YELLOW)clean$(RESET)";

fclean: clean
	rm -rf so_long.ber
	@echo "$(RED)remove $(NAME)$(RESET)";
	@rm -f $(NAME)

re: fclean all
	@echo "$(NAME) restart"

.PHONY: all clean fclean re
