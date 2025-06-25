# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xavier <xavier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 10:00:00 by xavier            #+#    #+#              #
#    Updated: 2025/06/19 10:00:00 by xavier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = get_next_line.a
TEST    = test_gnl

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -D BUFFER_SIZE=3

SRC     = get_next_line.c get_next_line_utils.c
OBJ     = $(SRC:.c=.o)

TEST_SRC = main.c
TEST_OBJ = $(TEST_SRC:.c=.o)

AR      = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

# 🧪 Target to build the test executable
test: $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(TEST)

debug: CFLAGS += -g
debug: test

clean:
	rm -f $(OBJ) $(TEST_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re debug test

