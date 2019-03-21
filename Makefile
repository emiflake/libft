# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/20 18:05:21 by nmartins      #+#    #+#                  #
#    Updated: 2019/03/20 19:26:51 by nmartins      ########   odam.nl          #
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
			 ft_strdup \
			 ft_strcpy \
			 ft_strchr \
			 ft_strrchr \
			 ft_strstr \
			 ft_strnstr \
			 ft_strcmp \
			 ft_strncmp \
			 ft_atoi \
			 ft_isalpha \
			 ft_isdigit \
			 ft_isalnum \
			 ft_isascii \
			 ft_isprint \
			 ft_tolower \
			 ft_toupper \
			 ft_memalloc \
			 ft_strnew \
			 ft_putchar \
			 ft_putstr \
			 ft_putendl \
			 ft_putchar_fd \
			 ft_putstr_fd \
			 ft_putendl_fd \
			 ft_str_drop_while \
			 ft_str_take_while \
			 ft_iswhite
			 

# do not configure
CC=gcc
INCLUDES=-I./
SRC=./
CFLAGS=-Werror -Wall -Wextra $(INCLUDES)
OBJECTS=$(patsubst %, %.o, $(OBJECT_NAMES))
OK_COLOR=\x1b[32;01m
RESET=\x1b[0m

#########
# rules #
#########
all: print_header $(NAME)

print_header:
	@echo "$(OK_COLOR)"
	@echo "o-----------------o"
	@echo "| Making libft... |"
	@echo "o-----------------o"
	@echo "$(RESET)"

debug: $(OBJECTS)
	$(CC) -o $(NAME) $^ $(CFLAGS) -g

$(NAME): $(OBJECTS)
	@ar rcs $@ $^
	@ranlib $@

%.o: $(SRC)/%.c
	@echo "Making object \x1b[4m$^$(RESET)"
	@$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	@echo "Cleaning objects"
	@rm -rf $(OBJECTS)

fclean: clean
	@echo "Cleaning $(NAME)"
	@rm -rf $(NAME)

re: fclean all

