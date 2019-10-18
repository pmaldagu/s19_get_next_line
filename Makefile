# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 09:46:31 by pmaldagu          #+#    #+#              #
#    Updated: 2019/10/18 13:46:43 by pmaldagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c \

NAME = libft.a

OBJS = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

GCC = gcc

RM = rm -rf

HEADER = ./libft.h

TEST = ./test/main.c


all: $(NAME)

$(OBJS): $(SRC)
	$(GCC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)   

test: $(TEST)
	$(GCC) $(FLAGS) $(NAME) $(TEST)
	./a.out

lib: all clean

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re lib
