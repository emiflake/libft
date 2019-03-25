# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                                 :+:    :+:       #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/20 18:05:21 by nmartins      #+#    #+#                  #
#    Updated: 2019/03/25 16:36:28 by nmartins            ########   odam.nl    #
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
			 ft_strncpy \
			 ft_strcat \
			 ft_strncat \
			 ft_strlcat \
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
			 ft_memdel \
			 ft_strnew \
			 ft_strdel \
			 ft_strclr \
			 ft_striter \
			 ft_striteri \
			 ft_strmap \
			 ft_strmapi \
			 ft_strequ \
			 ft_strnequ \
			 ft_strsub \
			 ft_strjoin \
			 ft_strtrim \
			 ft_strsplit \
			 ft_itoa \
			 ft_putchar \
			 ft_putstr \
			 ft_putendl \
			 ft_putnbr \
			 ft_putchar_fd \
			 ft_putstr_fd \
			 ft_putendl_fd \
			 ft_putnbr_fd \
			 ft_lstnew \
			 ft_lstdelone \
			 ft_lstdel \
			 ft_lstadd \
			 ft_lstiter \
			 ft_lstmap \
			 ft_str_drop_while \
			 ft_str_take_while \
			 ft_iswhite \
			 ft_strtolo \
			 ft_strtoup \
			 ft_memrcpy \
			 ft_strchrcount \
			 ft_strrev \
			 ft_print_memory


# do not configure
CC=gcc
INCLUDES=-I./
SRC=./
CFLAGS=-Werror -Wall -Wextra $(INCLUDES)
OBJECTS=$(patsubst %, %.o, $(OBJECT_NAMES))
SOURCES=$(patsubst %, %.c, $(OBJECT_NAMES))

# colors feel free to add more as you need them
OK_COLOR=\x1b[32;01m
RESET=\x1b[0m
UNDERLINE=\x1b[4m
BLUE=\x1b[36m
RED=\x1b[31m

#########
# rules #
#########
all: print_header $(NAME) success
success:
	@if [ $(shell printf  $$(($(num)))) -eq 0 ]; \
	then \
		echo "$(BLUE)Was already compiled 💤$(RESET)"; \
	else \
		echo "$(OK_COLOR)"; \
		echo "$(OK_COLOR)Sucessfully compiled $(RESET)"; \
		printf "Made $(UNDERLINE)$(BLUE)%d$(RESET) objects 🔥\n" $(shell printf $$(($(num)))); \
	fi

print_header:
	@$(eval num=0)
	@echo "$(OK_COLOR)"
	@echo "o--------------------o"
	@echo "| Making libft... 🐈  |"
	@echo "o--------------------o"
	@echo "$(RESET)"

debug:
	$(CC) -o $(NAME) $^ $(CFLAGS) -g

$(NAME): $(OBJECTS)
	@ar rcs $@ $^
	@ranlib $@

so:
	make CFLAGS=-fPIC
	$(CC) $(OBJECTS) -shared -o libft.so

%.o: $(SRC)/%.c
	@$(eval num=$(shell echo $$(($(num)+1))))
	@printf " - Making object $(UNDERLINE)$(BLUE)$^$(RESET)\n"
	@$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	@echo "🗑  $(RED)Cleaning objects$(RESET)"
	@rm -rf $(OBJECTS)

fclean: clean
	@echo "🗑  $(RED)Cleaning $(NAME)"
	@rm -rf $(NAME)

re: fclean all

