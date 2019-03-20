# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/20 18:05:21 by nmartins      #+#    #+#                  #
#    Updated: 2019/03/20 17:20:00 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#############
# variables #
#############

# configure
NAME=test.out

OBJECT_NAMES=run_all \
			 emitest/emitest

LIBFT=libft.a

# do not configure
CC=gcc
INCLUDES=-I./ -I./emitest/
SRC=./
CFLAGS=-Werror -Wall -Wextra $(INCLUDES)
OBJECTS=$(patsubst %, %.o, $(OBJECT_NAMES))
OK_COLOR=\x1b[32;01m
RESET=\e[0m

#########
# rules #
#########
all: $(NAME)

debug: $(LIBFT) $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(LIBFT) $(CFLAGS) -g

test: re
	@./$(NAME)

$(LIBFT):
	@make -s -C .. re
	@echo "Copying to tests..."
	@cp ../libft.a .
	@cp ../libft.h ./

$(NAME): $(LIBFT) $(OBJECTS)
	@echo "Making tests"
	@$(CC) -o $@ $(OBJECTS) $(LIBFT) $(CFLAGS)

%.o: $(SRC)/%.c
	@echo "Making object $^"
	@$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	@echo "Cleaning objects"
	@rm -rf $(OBJECTS)

ftclean:
	@echo "Cleaning libft"
	@rm -rf $(LIBFT)

fclean: clean
	@echo "Cleaning $(NAME)"
	@rm -rf $(NAME)

re: fclean ftclean all

