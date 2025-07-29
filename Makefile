# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: you <you@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 12:00:00 by you               #+#    #+#              #
#    Updated: 2025/07/28 12:00:00 by you              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER ?= 42
CPPFLAGS = -D BUFFER_SIZE=$(BUFFER)

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

test: $(NAME) main.o
	$(CC) $(CFLAGS) main.o $(NAME) -o test_gnl

main.o: main.c get_next_line.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c main.c -o main.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) test_gnl

re: fclean all

.PHONY: all clean fclean re test

