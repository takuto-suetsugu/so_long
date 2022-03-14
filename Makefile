# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 14:06:28 by tsuetsug          #+#    #+#              #
#    Updated: 2022/03/14 12:27:37 by tsuetsug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OFF		= \033[0m

NAME	= so_long

SRCS	= srcs/so_long.c srcs/import_file.c srcs/so_long_utils.c \
			srcs/import_file_error.c srcs/key_control.c srcs/destroy_window.c \

OBJ		= *.o

HEADERS	= includes/so_long.h

LIBFT	= libft/libft.a

PRINT_F = ft_printf/libftprintf.a

MINILIB	= minilibx_mms_20200219/libmlx.dylib

LIB_PATH = -L.

LIB_FLAG = -lmlx -lft -lftprintf

CC		= cc
CC_FLAGS= -Wall -Wextra -Werror
RM		= rm -f

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all:	$(NAME)

$(NAME): $(0BJ) $(LIBFT) $(PRINT_F) $(MINILIB)
	@echo "$(BWHITE)Compiling so_long...$(OFF)"
	$(CC) $(CC_FLAGS) -c $(SRCS) -I $(HEADERS)
	$(CC) -g -o $(NAME) $(OBJ) $(LIBFT) $(PRINT_F) $(CC_FLAGS) -L./minilibx_mms_20200219 -lmlx
	@echo "$(BGREEN)so_long build completed.$(OFF)"

$(LIBFT):
	@make -C libft

$(PRINT_F):
	@make -C ft_printf

$(MINILIB):
	@make -C minilibx_mms_20200219

clean:
	@echo "$(BWHITE)Removing object-files...$(OFF)"
	$(RM) $(OBJ)
	@make clean -C libft
	@make clean -C ft_printf
	@echo "$(BGREEN)Clean done.$(OFF)"

fclean:	clean
	@echo "$(BWHITE)Removing object-files and binary-files...$(OFF)"
	$(RM) $(NAME)
	@make clean -C minilibx_mms_20200219
	@make fclean -C libft
	@make fclean -C ft_printf
	@echo "$(BGREEN)Fclean done.$(OFF)"

re:		fclean all

.PHONY:		all clean fclean re