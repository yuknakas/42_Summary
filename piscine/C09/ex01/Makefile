# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 16:56:46 by yuknakas          #+#    #+#              #
#    Updated: 2024/08/29 13:13:33 by yuknakas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRC_DIR		=	srcs
OBJ_DIR		=	$(SRC_DIR)
INCLUDE_DIR	=	includes
LIB_NAME	=	libft.a
SRC_FILES	=	$(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_putstr.c \
				$(SRC_DIR)/ft_strcmp.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_swap.c
OBJ_FILES	= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%*.o)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	ar rcs $(LIB_NAME) $(OBJ_FILES)

$(OBJ_DIR)/%*.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all