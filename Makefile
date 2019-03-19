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

OBJECT_NAMES=ft_memset \
			 ft_bzero \
			 ft_memcpy \
			 ft_memccpy \
			 ft_memmove \
			 ft_memchr \
			 ft_memcmp \
			 ft_strlen \
			 ft_strdup

# do not configure
CC=gcc
INCLUDES=-I./includes
SRC=./srcs
CFLAGS=-Werror -Wall -Wextra $(INCLUDES)
OBJECTS=$(patsubst %, %.o, $(OBJECT_NAMES))
OK_COLOR=\x1b[32;01m
RESET=\e[0m

#########
# rules #
#########
all: print_header $(NAME)

print_header:
	@echo -e "$(OK_COLOR)"
	@echo -e "o-----------------o"
	@echo -e "| Making libft... |"
	@echo -e "o-----------------o"
	@echo -e "$(RESET)"

debug: $(OBJECTS)
	$(CC) -o $(NAME) $^ $(CFLAGS) -g

$(NAME): $(OBJECTS)
	@ar rcs $@ $^
	@ranlib $@

%.o: $(SRC)/%.c
	@echo -e "Making object \e[4m$^$(RESET)"
	@$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	@echo "Cleaning objects"
	@rm -rf $(OBJECTS)

fclean: clean
	@echo "Cleaning $(NAME)"
	@rm -rf $(NAME)

re: fclean all

