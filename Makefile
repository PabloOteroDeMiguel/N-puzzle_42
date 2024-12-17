# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablo <pablo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 12:17:44 by potero-d          #+#    #+#              #
#    Updated: 2024/12/17 17:58:54 by pablo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = src/main.cpp src/Game.cpp

CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra -Ilibs/SDL2/include
LDFLAGS = -Llibs/SDL2/lib -lSDL2 -Wl,-rpath=libs/SDL2/lib
SRC_DIR = src


OBJECTS=$(SOURCES:.cpp=.o)

NAME=npuzzle

RM = rm -f

all: $(SOURCES) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $(NAME)
	
.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS)
		
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re