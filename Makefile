# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/20 18:05:21 by nmartins      #+#    #+#                  #
#    Updated: 2019/02/26 21:00:31 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#############
# variables #
#############

# configure
NAME=libft.a

OBJECT_NAMES=memset \
			 bzero \
			 memcpy

# do not configure
CC=gcc
INCLUDES=-I./includes
SRC=./srcs
CFLAGS=-Werror -Wall -Wextra $(INCLUDES)
OBJECTS=$(patsubst %, %.o, $(OBJECT_NAMES))


#########
# rules #
#########
all: $(NAME)

debug: $(OBJECTS)
	$(CC) -o $(NAME) $^ $(CFLAGS) -g

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	ranlib $@

%.o: $(SRC)/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

