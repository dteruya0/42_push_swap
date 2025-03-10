# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 09:32:27 by dteruya           #+#    #+#              #
#    Updated: 2025/03/10 16:38:02 by dteruya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
LIB_DIR = libft
OBJ_DIR = obj

LIBFT = $(LIB_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c stack_init.c stack_utils.c \
		error_free.c list.c \

OBJ = $(SRCS:.c=.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(addprefix $(OBJ_DIR)/, $(OBJ))
	@$(MAKE) -C $(LIB_DIR) --no-print-directory
	$(CC) $(CFLAGS) -o $(NAME) $(addprefix $(OBJ_DIR)/, $(OBJ)) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re