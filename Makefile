# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 02:46:03 by mes-salh          #+#    #+#              #
#    Updated: 2024/08/03 05:49:05 by mes-salh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = exec/built_in.c exec/helpers.c exec/split.c exec/splitv2.c \
		exec/minishell.c exec/pwd.c exec/cd.c exec/helpers1.c \
		exec/helpers2.c exec/env.c exec/echo.c exec/export.c exec/unset.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

HEADER = exec/minishell.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lreadline -o $(NAME) $(OBJ)

exec/%.o: exec/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

m : all clean