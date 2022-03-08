# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 14:06:28 by tsuetsug          #+#    #+#              #
#    Updated: 2022/03/08 13:34:08 by tsuetsug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= so_long

SRCS	= srcs/so_long.c srcs/import_file.c srcs/so_long_utils.c \
			srcs/import_file_error.c srcs/key_control.c

OBJ		= *.o

HEADERS	= includes/so_long.h

LIBFT	= libft/libft.a

MLB_FLAGS = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

CC		= cc
CC_FLAGS= -Wall -Wextra -Werror
RM		= rm -f

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all:	$(NAME)

$(NAME):
	@echo "$(BWHITE)Compiling libraries...$(OFF)"
	${MAKE} -C libft
	@echo "$(BGREEN)Libraries done.$(OFF)"

	@echo "$(BWHITE)Compiling so_long...$(OFF)"
	$(CC) $(CC_FLAGS) -c $(SRCS) -I $(HEADERS)
	$(CC) -g -o $(NAME) $(OBJ) $(LIBFT) $(CC_FLAGS) $(MLB_FLAGS)
	@echo "$(BGREEN)so_long build completed.$(OFF)"
	
clean:
	@echo "$(BWHITE)Removing object-files...$(OFF)"
	$(RM) $(OBJ)
	@cd libft && $(MAKE) clean
	@echo "$(BGREEN)Clean done.$(OFF)"

fclean:	clean
	@echo "$(BWHITE)Removing object-files and binary-files...$(OFF)"
	$(RM) $(NAME)
	@cd libft && $(MAKE) fclean
	@echo "$(BGREEN)Fclean done.$(OFF)"

re:		fclean all